#define _GNU_SOURCE
#include <unistd.h>
#include <signal.h>
#include "syscall.h"
#include "libc.h"

int setgroups(size_t count, const gid_t list[])
{
	// TODO (arca): setgroups
	return -1;
}
