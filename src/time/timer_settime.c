#include <time.h>
#include <limits.h>
#include "pthread_impl.h"

#define IS32BIT(x) !((x)+0x80000000ULL>>32)

int timer_settime(timer_t t, int flags, const struct itimerspec *restrict val, struct itimerspec *restrict old)
{
	// TODO (arca): timer_settime
	return -1;
}
