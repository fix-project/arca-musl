#define _GNU_SOURCE
#include <sys/wait.h>
#include <sys/resource.h>
#include <string.h>
#include <errno.h>
#include "syscall.h"

pid_t wait4(pid_t pid, int *status, int options, struct rusage *ru)
{
	// TODO (arca): wait4
	return -1;
}
