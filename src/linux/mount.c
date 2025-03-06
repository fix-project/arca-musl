#include <sys/mount.h>
#include "syscall.h"

int mount(const char *special, const char *dir, const char *fstype, unsigned long flags, const void *data)
{
	// TODO (arca): mount
	return -1;
}

int umount(const char *special)
{
	return umount2(special, 0);
}

int umount2(const char *special, int flags)
{
	// TODO (arca): umount2
	return -1;
}
