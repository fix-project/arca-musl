#include <termios.h>
#include <sys/ioctl.h>
#include "syscall.h"

int tcdrain(int fd)
{
	return ioctl(fd, TCSBRK, (void*)1);
}
