#ifndef _ARCA_SYS_THREAD
#define _ARCA_SYS_THREAD

#include <sys/types.h>

pid_t __sys_set_tid_address(volatile int *tidptr);

#endif
