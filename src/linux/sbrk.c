#define _BSD_SOURCE
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include "syscall.h"

void *sbrk(intptr_t inc)
{
	// TODO (arca): sbrk
	return (void *)-1;
}
