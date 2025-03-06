#include <sys/inotify.h>
#include <errno.h>
#include "syscall.h"

int inotify_init()
{
	return inotify_init1(0);
}
int inotify_init1(int flags)
{
	// TODO (arca): inotify_init1
	return -1;
}

int inotify_add_watch(int fd, const char *pathname, uint32_t mask)
{
	// TODO (arca): inotify_add_watch
	return -1;
}

int inotify_rm_watch(int fd, int wd)
{
	// TODO (arca): inotify_rm_watch
	return -1;
}
