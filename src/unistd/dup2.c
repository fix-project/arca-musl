#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "syscall.h"

int dup2(int old, int new)
{
	return dup3(old, new, 0);
}
