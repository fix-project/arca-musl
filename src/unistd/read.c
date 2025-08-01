#include <unistd.h>
#include "syscall.h"

ssize_t read(int fd, void *buf, size_t count)
{
	return __sys_read_cp(fd, buf, count);
}
