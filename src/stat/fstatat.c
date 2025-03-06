#define _BSD_SOURCE
#include "syscall.h"
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>

int __fstatat(int fd, const char *restrict path, struct stat *restrict st,
              int flag) {
  // TODO (arca): __fstatat
  return -1;
}

weak_alias(__fstatat, fstatat);
