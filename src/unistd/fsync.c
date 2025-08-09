#include <unistd.h>
#include "syscall.h"

int fsync(int fd)
{
	return __sys_fsync(fd);
}
