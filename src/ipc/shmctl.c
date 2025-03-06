#include <sys/shm.h>
#include <endian.h>
#include "syscall.h"
#include "ipc.h"

#if __BYTE_ORDER != __BIG_ENDIAN
#undef SYSCALL_IPC_BROKEN_MODE
#endif

int shmctl(int id, int cmd, struct shmid_ds *buf)
{
	// TODO (arca): shmctl
	return -1;
}
