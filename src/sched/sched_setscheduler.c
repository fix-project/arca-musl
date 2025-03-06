#include <sched.h>
#include <errno.h>
#include "syscall.h"

int sched_setscheduler(pid_t pid, int sched, const struct sched_param *param)
{
	// TODO (arca): sched_setscheduler
	return -1;
}
