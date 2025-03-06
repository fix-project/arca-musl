#include <sys/signalfd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include "syscall.h"

int signalfd(int fd, const sigset_t *sigs, int flags)
{
	// TODO (arca): signalfd
	return -1;
}
