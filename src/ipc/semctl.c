#include <sys/sem.h>
#include <stdarg.h>
#include <endian.h>
#include "syscall.h"
#include "ipc.h"

#if __BYTE_ORDER != __BIG_ENDIAN
#undef SYSCALL_IPC_BROKEN_MODE
#endif

int semctl(int id, int num, int cmd, ...)
{
	union semun arg = {0};
	va_list ap;
	switch (cmd & ~IPC_TIME64) {
	case SETVAL: case GETALL: case SETALL: case IPC_SET:
	case IPC_INFO: case SEM_INFO:
	case IPC_STAT & ~IPC_TIME64:
	case SEM_STAT & ~IPC_TIME64:
	case SEM_STAT_ANY & ~IPC_TIME64:
		va_start(ap, cmd);
		arg = va_arg(ap, union semun);
		va_end(ap);
	}

	// TODO (arca): semctl
	return -1;
}
