#include <stdlib.h>
#include "syscall.h"

_Noreturn void _Exit(int ec) {
	__sys_exit_group(ec);
	for (;;)
		__sys_exit(ec);
}
