#include "syscall.h"
#include <errno.h>
#include <sys/socket.h>
#include <sys/time.h>

#define IS32BIT(x) !((x) + 0x80000000ULL >> 32)
#define CLAMP(x) (int)(IS32BIT(x) ? (x) : 0x7fffffffU + ((0ULL + (x)) >> 63))

int setsockopt(int fd, int level, int optname, const void *optval,
               socklen_t optlen) {
  // TODO (arca): setsockopt
  return -1;
}
