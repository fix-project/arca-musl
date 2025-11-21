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
#define TwoMB  (1 << 21)
#define OneGB  (1 << 30)

static char *MMAP_REGION_START = NULL;
static char *MMAP_REGION = NULL;

static void set_mmap_region(void) {
  if (!MMAP_REGION_START) {
    uintptr_t brk = (uintptr_t)BREAK;
    uintptr_t offset_from_aligned = brk % TwoMB;
    if (offset_from_aligned != 0) {
      brk += TwoMB - offset_from_aligned;
    }
    MMAP_REGION_START = (char *)brk;
  }
  if (!MMAP_REGION) {
    MMAP_REGION = MMAP_REGION_START;
  }
}

void *__sys_brk(void *p)
{
  set_mmap_region();
	if (p >= (void *)BREAK && p <= MMAP_REGION_START) {
		BREAK = p;
	}
        while (MAPPED < BREAK) {
          if ((uintptr_t)MAPPED % 4096) {
            MAPPED++;
          } else {
            arcad page = arca_page_create(4096);
            // TODO (Arca): handle errors
            struct arca_entry entry = {
              .mode = __MODE_read_write,
              .data = page,
            };
            arca_mmap(MAPPED, &entry);
            if (entry.datatype != __TYPE_null)
              arca_drop(entry.data);
            MAPPED += 4096;
          }
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
        size_t amount = 0;
	while (amount < len) {
		arcad data;
                int mode;
                if (prot == PROT_NONE) {
                  data = 4096;
                  mode = __MODE_none;
                } else {
                  data = arca_page_create(4096);
                  mode = (prot & PROT_WRITE) ? __MODE_read_write : __MODE_read_only;
                }
		// TODO (Arca): handle errors
		struct arca_entry entry = {
		    .mode = mode,
		    .data = data,
		};
		arca_mmap(start + amount, &entry);
		if (entry.datatype != __TYPE_null)
			arca_drop(entry.data);
		amount += 4096;
	}
        if (!(flags & MAP_FIXED)) {
          MMAP_REGION = start + amount;
        }
	return start;
}

int __sys_mprotect(void *addr, size_t len, int prot) {
  char *start = (char *)(((uintptr_t)addr / 4096) * 4096);
  char *end = (char *)addr + len;
  while ((uintptr_t)end % 4096) {
    end++;
  }
  size_t n = (end - start) / 4096;
  for (int i = 0; i < n; i++) {
    void *p = start + i*4096;
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

int __sys_munmap(void *addr, size_t len) {
  return mprotect(addr, len, PROT_NONE);
}
