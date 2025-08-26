#ifndef _ARCA_SYS_IO
#define _ARCA_SYS_IO
#include <unistd.h>
#include <sys/uio.h>
#include <fcntl.h>

int __sys_isatty(int fd);
int __sys_open(const char *path, int flags, mode_t mode);
int __sys_open_cp(const char *path, int flags, mode_t mode);
int __sys_close(int fd);
int __sys_close_cp(int fd);
ssize_t __sys_read(int fd, void *buf, size_t count);
ssize_t __sys_read_cp(int fd, void *buf, size_t count);
ssize_t __sys_readv(int fd, const struct iovec *iov, int iovcnt);
ssize_t __sys_writev(int fd, const struct iovec *iov, int iovcnt);
[[noreturn]] void __sys_exit_group(int status);
[[noreturn]] void __sys_exit(int status);
int __sys_fsync(int fd);
off_t __sys_lseek(int fd, off_t offset, int whence);

#endif
