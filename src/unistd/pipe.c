#include <unistd.h>
#include "syscall.h"

int pipe(int fd[2])
{
	pipe2(fd, 0);
}
