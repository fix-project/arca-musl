#include <sys/mman.h>
#include "syscall.h"

static void dummy(void) { }
weak_alias(dummy, __vm_wait);

int __munmap(void *start, size_t len)
{
	// TODO (arca): munmap
	return -1;
}

weak_alias(__munmap, munmap);
