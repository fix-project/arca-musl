#include <sys/socket.h>
#include <limits.h>
#include <string.h>
#include <errno.h>
#include "syscall.h"

ssize_t sendmsg(int fd, const struct msghdr *msg, int flags)
{
	// TODO (arca): sendmsg
	return -1;
}
