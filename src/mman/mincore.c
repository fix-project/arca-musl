#define _GNU_SOURCE
#include <sys/mman.h>
#include "syscall.h"

int mincore (void *addr, size_t len, unsigned char *vec)
{
	// TODO (arca): mincore
	return -1;
}
