#include "pthread_impl.h"
#include "lock.h"

int pthread_setschedprio(pthread_t t, int prio)
{
	int r;
	sigset_t set;
	__block_app_sigs(&set);
	LOCK(t->killlock);
	r = !t->tid ? ESRCH : -sched_setparam(t->tid, (const struct sched_param *)&prio);
	UNLOCK(t->killlock);
	__restore_sigs(&set);
	return r;
}
