#define _GNU_SOURCE 1
#include <sys/mman.h>
#include "syscall.h"

int mlock2(const void *addr, size_t len, unsigned flags)
{
	// TODO (arca): mlock2
	return -1;
}
