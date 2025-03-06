#include "syscall.h"
#include <errno.h>
#include <time.h>

#define IS32BIT(x) !((x) + 0x80000000ULL >> 32)
#define CLAMP(x) (int)(IS32BIT(x) ? (x) : 0x7fffffffU + ((0ULL + (x)) >> 63))

int __clock_nanosleep(clockid_t clk, int flags, const struct timespec *req,
                      struct timespec *rem) {
  // TODO (arca): clock_nanosleep
  return -1;
}

weak_alias(__clock_nanosleep, clock_nanosleep);
