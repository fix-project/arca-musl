#define _GNU_SOURCE
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "syscall.h"
#include "pthread_impl.h"

int faccessat(int fd, const char *filename, int amode, int flag)
{
	// TODO (arca): faccessat
	return -1;
}
