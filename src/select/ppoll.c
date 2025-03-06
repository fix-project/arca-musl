#define _BSD_SOURCE
#include "syscall.h"
#include <errno.h>
#include <poll.h>
#include <signal.h>

#define IS32BIT(x) !((x) + 0x80000000ULL >> 32)
#define CLAMP(x) (int)(IS32BIT(x) ? (x) : 0x7fffffffU + ((0ULL + (x)) >> 63))

int ppoll(struct pollfd *fds, nfds_t n, const struct timespec *to,
          const sigset_t *mask) {
  // TODO (arca): ppoll
  return -1;
}
