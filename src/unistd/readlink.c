#include <unistd.h>
#include <fcntl.h>
#include "syscall.h"

ssize_t readlink(const char *restrict path, char *restrict buf, size_t bufsize)
{
	// TODO (arca): readlink
	return -1;
}
