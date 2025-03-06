#define _GNU_SOURCE
#include <sys/sem.h>
#include <errno.h>
#include "syscall.h"
#include "ipc.h"

#define IS32BIT(x) !((x)+0x80000000ULL>>32)
#define CLAMP(x) (int)(IS32BIT(x) ? (x) : 0x7fffffffU+((0ULL+(x))>>63))

#if !defined(SYS_semtimedop) && !defined(SYS_ipc) || \
	SYS_semtimedop == SYS_semtimedop_time64
#define NO_TIME32 1
#else
#define NO_TIME32 0
#endif

int semtimedop(int id, struct sembuf *buf, size_t n, const struct timespec *ts)
{
	// TODO (arca): semtimedop
	return -1;
}
