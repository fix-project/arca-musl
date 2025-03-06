#define _GNU_SOURCE
#include <sys/resource.h>
#include <errno.h>
#include "syscall.h"

#define FIX(x) do{ if ((x)>=SYSCALL_RLIM_INFINITY) (x)=RLIM_INFINITY; }while(0)

int getrlimit(int resource, struct rlimit *rlim)
{
	int ret = prlimit(0, resource, 0, rlim);
	if (!ret) {
		FIX(rlim->rlim_cur);
		FIX(rlim->rlim_max);
	}
	return ret;
}
