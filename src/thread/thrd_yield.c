#include "syscall.h"
#include <sched.h>
#include <threads.h>

void thrd_yield() { sched_yield(); }
