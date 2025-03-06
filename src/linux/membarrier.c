#include <sys/membarrier.h>
#include <semaphore.h>
#include <signal.h>
#include <string.h>
#include "pthread_impl.h"
#include "syscall.h"

static void dummy_0(void)
{
}

weak_alias(dummy_0, __tl_lock);
weak_alias(dummy_0, __tl_unlock);

static sem_t barrier_sem;

static void bcast_barrier(int s)
{
	sem_post(&barrier_sem);
}

int __membarrier(int cmd, int flags)
{
	// TODO (arca): __membarrier
	return -1;
}

void __membarrier_init(void)
{
	/* If membarrier is linked, attempt to pre-register to be able to use
	 * the private expedited command before the process becomes multi-
	 * threaded, since registering later has bad, potentially unbounded
	 * latency. This syscall should be essentially free, and it's arguably
	 * a mistake in the API design that registration was even required.
	 * For other commands, registration may impose some cost, so it's left
	 * to the application to do so if desired. Unfortunately this means
	 * library code initialized after the process becomes multi-threaded
	 * cannot use these features without accepting registration latency. */
	__membarrier(MEMBARRIER_CMD_REGISTER_PRIVATE_EXPEDITED, 0);
}

weak_alias(__membarrier, membarrier);
