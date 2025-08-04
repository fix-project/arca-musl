#include <arca/arca.h>
#include <arca/log.h>
#include <arca/thread.h>

pid_t __sys_set_tid_address(volatile int *tidptr)
{
  // TODO: does this need to be handled if we only have one thread?
	return 0;
}
