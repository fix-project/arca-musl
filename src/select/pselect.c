#include "syscall.h"
#include <errno.h>
#include <signal.h>
#include <stdint.h>
#include <sys/select.h>

#define IS32BIT(x) !((x) + 0x80000000ULL >> 32)
#define CLAMP(x) (int)(IS32BIT(x) ? (x) : 0x7fffffffU + ((0ULL + (x)) >> 63))

int pselect(int n, fd_set *restrict rfds, fd_set *restrict wfds,
            fd_set *restrict efds, const struct timespec *restrict ts,
            const sigset_t *restrict mask) {
  // TODO (arca): pselect
  return -1;
}
