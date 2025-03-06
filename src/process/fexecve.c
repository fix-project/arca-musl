#define _GNU_SOURCE
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "syscall.h"

int fexecve(int fd, char *const argv[], char *const envp[])
{
	// TODO (arca): fexecve
	return -1;
}
