#include "syscall.h"
#include <sys/xattr.h>

ssize_t getxattr(const char *path, const char *name, void *value, size_t size) {
  // TODO (arca): getxattr
  return -1;
}

ssize_t lgetxattr(const char *path, const char *name, void *value,
                  size_t size) {
  // TODO (arca): lgetxattr
  return -1;
}

ssize_t fgetxattr(int filedes, const char *name, void *value, size_t size) {
  // TODO (arca): fgetxattr
  return -1;
}

ssize_t listxattr(const char *path, char *list, size_t size) {
  // TODO (arca): listxattr
  return -1;
}

ssize_t llistxattr(const char *path, char *list, size_t size) {
  // TODO (arca): llistxattr
  return -1;
}

ssize_t flistxattr(int filedes, char *list, size_t size) {
  // TODO (arca): flistxattr
  return -1;
}

int setxattr(const char *path, const char *name, const void *value, size_t size,
             int flags) {
  // TODO (arca): setxattr
  return -1;
}

int lsetxattr(const char *path, const char *name, const void *value,
              size_t size, int flags) {
  // TODO (arca): lsetxattr
  return -1;
}

int fsetxattr(int filedes, const char *name, const void *value, size_t size,
              int flags) {
  // TODO (arca): fsetxattr
  return -1;
}

int removexattr(const char *path, const char *name) {
  // TODO (arca): removexattr
  return -1;
}

int lremovexattr(const char *path, const char *name) {
  // TODO (arca): lremovexattr
  return -1;
}

int fremovexattr(int fd, const char *name) {
  // TODO (arca): fremovexattr
  return -1;
}
