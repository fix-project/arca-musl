#include "syscall.h"
#include <sys/fanotify.h>

int fanotify_init(unsigned flags, unsigned event_f_flags)
{
	// TODO (arca): fanotify_init
	return -1;
}

int fanotify_mark(int fanotify_fd, unsigned flags, unsigned long long mask,
	          int dfd, const char *pathname)
{
	// TODO (arca): fanotify_mark
	return -1;
}

