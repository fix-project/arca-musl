#include <sys/mman.h>
#include "syscall.h"

int __madvise(void *addr, size_t len, int advice)
{
	// TODO (arca): madvise
	return -1;
}

weak_alias(__madvise, madvise);
