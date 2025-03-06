#define _GNU_SOURCE
#include "syscall.h"
#include <errno.h>
#include <limits.h>
#include <sys/socket.h>
#include <time.h>

#define IS32BIT(x) !((x) + 0x80000000ULL >> 32)
#define CLAMP(x) (int)(IS32BIT(x) ? (x) : 0x7fffffffU + ((0ULL + (x)) >> 63))

hidden void __convert_scm_timestamps(struct msghdr *, socklen_t);

int recvmmsg(int fd, struct mmsghdr *msgvec, unsigned int vlen,
             unsigned int flags, struct timespec *timeout) {
  // TODO (arca): recvmmsg
  return -1;
}
