#define _GNU_SOURCE
#include <sys/resource.h>
#include "syscall.h"

#define FIX(x) do{ if ((x)>=SYSCALL_RLIM_INFINITY) (x)=RLIM_INFINITY; }while(0)

int prlimit(pid_t pid, int resource, const struct rlimit *new_limit, struct rlimit *old_limit)
{
	// TODO (arca): prlimit	
	return -1;
}
