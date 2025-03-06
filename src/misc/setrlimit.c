#define _GNU_SOURCE
#include <sys/resource.h>
#include <errno.h>
#include "syscall.h"
#include "libc.h"

#define MIN(a, b) ((a)<(b) ? (a) : (b))
#define FIX(x) do{ if ((x)>=SYSCALL_RLIM_INFINITY) (x)=RLIM_INFINITY; }while(0)

int setrlimit(int resource, const struct rlimit *rlim)
{
	struct rlimit tmp;
	if (SYSCALL_RLIM_INFINITY != RLIM_INFINITY) {
		tmp = *rlim;
		FIX(tmp.rlim_cur);
		FIX(tmp.rlim_max);
		rlim = &tmp;
	}
	int ret = prlimit(0, resource, rlim, 0);
	return __syscall_ret(ret);
}
