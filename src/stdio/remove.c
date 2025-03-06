#include "syscall.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int remove(const char *path)
{
	int r = unlink(path);
	if (r==-EISDIR) r = rmdir(path);
	return __syscall_ret(r);
}
