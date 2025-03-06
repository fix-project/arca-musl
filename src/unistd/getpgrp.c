#include <unistd.h>
#include "syscall.h"

pid_t getpgrp(void)
{
	return getpgid(0);
}
