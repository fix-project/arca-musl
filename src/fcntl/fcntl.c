#define _GNU_SOURCE
#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>

int fcntl(int fd, int cmd, ...)
{
	unsigned long arg;
	va_list ap;
	va_start(ap, cmd);
	arg = va_arg(ap, unsigned long);
	va_end(ap);
	
	// TODO (arca): fnctl
	return -1;
}
