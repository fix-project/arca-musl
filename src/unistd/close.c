#include <unistd.h>
#include <errno.h>
#include "aio_impl.h"
#include "syscall.h"

static int dummy(int fd) { return fd; }

weak_alias(dummy, __aio_close);

int close(int fd)
{
	fd = __aio_close(fd);
	int r = __sys_close_cp(fd);
	if (r == -EINTR)
		r = 0;
	return __syscall_ret(r);
}
