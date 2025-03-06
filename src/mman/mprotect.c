#include <sys/mman.h>
#include "libc.h"
#include "syscall.h"

int __mprotect(void *addr, size_t len, int prot)
{
	// TODO (arca): mprotect
	return -1;
}

weak_alias(__mprotect, mprotect);
