#include <sys/timerfd.h>
#include <errno.h>
#include "syscall.h"

#define IS32BIT(x) !((x)+0x80000000ULL>>32)

int timerfd_create(int clockid, int flags)
{
	// TODO (arca): timerfd_create
	return -1;
}

int timerfd_settime(int fd, int flags, const struct itimerspec *new, struct itimerspec *old)
{
	// TODO (arca): timerfd_settime
	return -1;
}

int timerfd_gettime(int fd, struct itimerspec *cur)
{
	// TODO (arca): timerfd_gettime
	return -1;
}
