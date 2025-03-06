#include "ipc.h"
#include "syscall.h"
#include <endian.h>
#include <sys/msg.h>

#if __BYTE_ORDER != __BIG_ENDIAN
#undef SYSCALL_IPC_BROKEN_MODE
#endif

int msgctl(int q, int cmd, struct msqid_ds *buf) {
  // TODO (arca): msgctl
  return -1;
}
