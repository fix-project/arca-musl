#include <sys/epoll.h>
#include <signal.h>
#include <errno.h>
#include "syscall.h"

int epoll_create(int size)
{
	if (size<=0) return __syscall_ret(-EINVAL);
	return epoll_create1(0);
}

int epoll_create1(int flags)
{
	// TODO (arca): epoll_create1
	return -1;
}

int epoll_ctl(int fd, int op, int fd2, struct epoll_event *ev)
{
	// TODO (arca): epoll_ctl
	return -1;
}

int epoll_pwait(int fd, struct epoll_event *ev, int cnt, int to, const sigset_t *sigs)
{
	// TODO (arca): epoll_pwait
	return -1;
}

int epoll_wait(int fd, struct epoll_event *ev, int cnt, int to)
{
	return epoll_pwait(fd, ev, cnt, to, 0);
}
