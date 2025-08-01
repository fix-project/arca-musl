#include <unistd.h>
#include <errno.h>
#include "syscall.h"

int isatty(int fd)
{
	unsigned long r = __sys_isatty(fd);
	if (r == 1) return 1;
	if (errno != EBADF) errno = ENOTTY;
	return 0;
}
