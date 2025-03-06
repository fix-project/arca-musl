#define _GNU_SOURCE
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "syscall.h"

int __dup3(int old, int new, int flags)
{
	// TODO (arca): dup3
	return -1;
}

weak_alias(__dup3, dup3);
