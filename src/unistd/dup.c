#include <unistd.h>
#include "syscall.h"

int dup(int fd)
{
	return dup3(fd, -1, 0);
}
