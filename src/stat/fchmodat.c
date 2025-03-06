#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "syscall.h"

int fchmodat(int fd, const char *path, mode_t mode, int flag)
{
	// TODO (arca): fchmodat
	return -1;
}
