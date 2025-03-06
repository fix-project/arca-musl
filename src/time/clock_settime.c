#include <time.h>
#include <errno.h>
#include "syscall.h"

#define IS32BIT(x) !((x)+0x80000000ULL>>32)

int clock_settime(clockid_t clk, const struct timespec *ts)
{
	// TODO (arca): clock_settime
	return -1;
}
