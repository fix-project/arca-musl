#include "syscall.h"
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/time.h>

#define IS32BIT(x) !((x) + 0x80000000ULL >> 32)
#define NS_SPECIAL(ns) ((ns) == UTIME_NOW || (ns) == UTIME_OMIT)

int utimensat(int fd, const char *path, const struct timespec times[2],
              int flags) {
  // TODO (arca): utimensat
  return -1;
}
