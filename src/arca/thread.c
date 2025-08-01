#include <arca/arca.h>
#include <arca/log.h>
#include <arca/thread.h>

pid_t __sys_set_tid_address(volatile int *tidptr)
{
	LOG_UNIMPL();
	return 0;
}
