#include <sys/personality.h>
#include "syscall.h"
#ifdef SYS_personality
int personality(unsigned long persona)
{
	// TODO (arca): personality
	return -1;
}
#endif
