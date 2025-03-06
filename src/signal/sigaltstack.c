#include <signal.h>
#include <errno.h>
#include "syscall.h"

int sigaltstack(const stack_t *restrict ss, stack_t *restrict old)
{
	// TODO (arca): sigaltstack
	return -1;
}
