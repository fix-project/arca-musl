#include "syscall.h"

#ifdef SYS_iopl
#include <sys/io.h>

int iopl(int level)
{
	// TODO (arca): iopl
	return -1;
}
#endif
