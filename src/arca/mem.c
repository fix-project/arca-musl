#include "arca/asm.h"
#include "arca/sys.h"
#include "sys/mman.h"
#include <arca/arca.h>
#include <arca/mem.h>
#include <assert.h>
#include <errno.h>

extern char _end;
static char *BREAK = &_end;
static char *HEAP = &_end;
static char *MAPPED = &_end;

void *__sys_brk(void *p)
{
	if (p >= (void *)BREAK) {
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
	if (!len) {
		errno = EINVAL;
		return MAP_FAILED;
	}

	if (!(flags & MAP_PRIVATE || flags & MAP_SHARED)) {
		arca_log("invalid mapping: neither private nor shared");
		errno = EINVAL;
		return MAP_FAILED;
	}

	if (!(flags & MAP_ANON)) {
		arca_log("invalid mapping: not anon");
		errno = EBADF;
		return MAP_FAILED;
	}

	if (flags & MAP_FIXED) {
		if ((char *)addr + off * 4096 >= BREAK) {
			arca_log("invalid mapping: fixed above break");
			errno = EINVAL;
			return MAP_FAILED;
		}
	}

	while ((uintptr_t)HEAP % 4096) {
		HEAP++;
	}

	// TODO (Arca): don't just bump allocate
	char *old = HEAP;
	while (HEAP - old < len) {
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
		arca_mmap(HEAP, &entry);
		if (entry.datatype != __TYPE_null)
			arca_drop(entry.data);
		HEAP += 4096;
	}
	return old;
}
