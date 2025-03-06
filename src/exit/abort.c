#include <stdlib.h>
#include <signal.h>
#include "pthread_impl.h"
#include "atomic.h"
#include "lock.h"
#include "ksigaction.h"

_Noreturn void abort(void)
{
	raise(SIGABRT);

	/* If there was a SIGABRT handler installed and it returned, or if
	 * SIGABRT was blocked or ignored, take an AS-safe lock to prevent
	 * sigaction from installing a new SIGABRT handler, uninstall any
	 * handler that may be present, and re-raise the signal to generate
	 * the default action of abnormal termination. */
	__block_all_sigs(0);
	LOCK(__abort_lock);
	__sigaction(SIGABRT,
		(struct sigaction*)(&(struct k_sigaction){.handler = SIG_DFL}), 0);
	__tkill(__pthread_self()->tid, SIGABRT);
	__sigproc_mask(SIG_UNBLOCK,
		(sigset_t *)(&(long[_NSIG/(8*sizeof(long))]){1UL<<(SIGABRT-1)}), 0);

	/* Beyond this point should be unreachable. */
	a_crash();
	raise(SIGKILL);
	_Exit(127);
}
