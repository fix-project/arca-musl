#include "arca/asm.h"
#include "arca/sys.h"
#include "sys/mman.h"
#include <arca/arca.h>
#include <arca/mem.h>
#include <assert.h>
#include <errno.h>

extern char _end;
static char *BREAK = &_end;
static char *MAPPED = &_end;

#define FourKB (1 << 12)
#define TwoMB (1 << 21)
#define OneGB (1 << 30)

static char *MMAP_REGION_START = NULL;
static char *MMAP_REGION = NULL;

static void *align(void *p, size_t align)
{
	uintptr_t x = (uintptr_t)p;
	uintptr_t offset_from_aligned = x % align;
	if (offset_from_aligned != 0) {
		x += align - offset_from_aligned;
	}
	return (void *)x;
}

static unsigned roundup(unsigned x, size_t align)
{
	unsigned offset_from_aligned = x % align;
	if (offset_from_aligned != 0) {
		x += align - offset_from_aligned;
	}
	return x;
}

static void set_mmap_region(void)
{
	if (!MMAP_REGION_START) {
		MMAP_REGION_START = align(BREAK, OneGB);
	}
	if (!MMAP_REGION) {
		MMAP_REGION = MMAP_REGION_START;
	}
}

void *__sys_brk(void *p)
{
	set_mmap_region();
	if (p >= (void *)BREAK && p <= (void *)MMAP_REGION_START) {
		BREAK = p;
	}
	MAPPED = align(MAPPED, 4096);
	if (BREAK > MAPPED) {
		int64_t result =
		    arca_compat_mmap(MAPPED, BREAK - MAPPED, __MODE_read_write);
		if (result < 0) {
			errno = ENOMEM;
			return NULL;
		}
		MAPPED = BREAK;
	}
	return BREAK;
}

void *__sys_mmap(void *addr, size_t len, int prot, int flags, int filedes,
                 off_t off)
{
	return __sys_mmap2(addr, len, prot, flags, filedes,
	                   ((off - 1) / 4096) + 1);
}

void *__sys_mmap2(void *addr, size_t len, int prot, int flags, int filedes,
                  unsigned long off)
{
	set_mmap_region();
	if (!len) {
		errno = EINVAL;
		return MAP_FAILED;
	}

	if (!(flags & MAP_PRIVATE || flags & MAP_SHARED)) {
		errno = EINVAL;
		return MAP_FAILED;
	}

	if (!(flags & MAP_ANON)) {
		errno = EBADF;
		return MAP_FAILED;
	}

	char *start;
	if (flags & MAP_FIXED) {
		start = (char *)addr;
	} else {
		while ((uintptr_t)MMAP_REGION % 4096) {
			MMAP_REGION++;
		}
		start = MMAP_REGION;
	}

	// TODO (Arca): don't just bump allocate
	unsigned mode;
	if (prot == PROT_NONE) {
		mode = __MODE_none;
	} else if (prot & PROT_WRITE) {
		mode = __MODE_read_write;
	} else {
		mode = __MODE_read_only;
	};
	int64_t result = arca_compat_mmap(start, len, mode);
	if (result < 0) {
		errno = ENOMEM;
		return MAP_FAILED;
	}
	if (!(flags & MAP_FIXED)) {
		MMAP_REGION = start + roundup(len, 4096);
	}
	return start;
}

int __sys_mprotect(void *addr, size_t len, int prot)
{
	char *start = (char *)(((uintptr_t)addr / 4096) * 4096);
	char *end = (char *)addr + len;
	while ((uintptr_t)end % 4096) {
		end++;
	}
	size_t n = (end - start) / 4096;
	for (int i = 0; i < n; i++) {
		void *p = start + i * 4096;
		int mode;
		if (prot == PROT_NONE) {
			mode = __MODE_none;
		} else if (prot & PROT_WRITE) {
			mode = __MODE_read_write;
		} else {
			mode = __MODE_read_only;
		}
		arca_mprotect(p, mode);
	}
	return 0;
}

int __sys_munmap(void *addr, size_t len)
{
	return mprotect(addr, len, PROT_NONE);
}
