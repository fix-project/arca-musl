#ifndef _INTERNAL_SYSCALL_H
#define _INTERNAL_SYSCALL_H

#define __NEED_uint64_t
#define __NEED_size_t
#define __NEED_uint8_t

#include "syscall_arch.h"
#include <bits/alltypes.h>
#include <errno.h>
#include <features.h>
#include <sys/syscall.h>

#ifndef SYSCALL_RLIM_INFINITY
#define SYSCALL_RLIM_INFINITY (~0ULL)
#endif

#ifndef __scc
#define __scc(X) ((long)(X))
typedef long syscall_arg_t;
#endif

long __syscall_ret(unsigned long);

static inline long syscall_nop(void) { return syscall(__SYS_NOP); }

static inline long syscall_null(uint64_t dst) {
  return syscall(__SYS_NULL, dst);
}

static inline long syscall_resize(size_t len) {
  return syscall(__SYS_RESIZE, len);
}

static inline long syscall_exit(uint64_t src) {
  return syscall(__SYS_EXIT, src);
}

static inline long syscall_len(uint64_t src, uint64_t *dst) {
  return syscall(__SYS_LEN, src, dst);
}

static inline long syscall_read_blob(uint64_t src, uint8_t *buffer, size_t len) {
  return syscall(__SYS_READ, src, __scc(buffer), len);
}

static inline long syscall_read_tree(uint64_t src, uint64_t *keys, size_t len) {
  return syscall(__SYS_READ, src, __scc(keys), len);
}

static inline long syscall_type(uint64_t src) {
  return syscall(__SYS_TYPE, src);
}

static inline long syscall_create_blob(uint64_t dst, const uint8_t *src,
                                       size_t len) {
  return syscall(__SYS_CREATE_BLOB, dst, __scc(src), len);
}

static inline long syscall_create_tree(uint64_t dst, const uint64_t *srcs,
                                       size_t len) {
  return syscall(__SYS_CREATE_TREE, dst, __scc(srcs), len);
}

static inline long syscall_continuation(uint64_t dst) {
  return syscall(__SYS_CONTINUATION, dst);
}

static inline long syscall_prompt(uint64_t dst) {
  return syscall(__SYS_PROMPT, dst);
}

static inline long syscall_perform(uint64_t src, uint64_t dst) {
  return syscall(__SYS_PERFORM, src, dst);
}

static inline long syscall_apply(uint64_t lambda, uint64_t arg) {
  return syscall(__SYS_APPLY, lambda, arg);
}

#define __SC_socket 1
#define __SC_bind 2
#define __SC_connect 3
#define __SC_listen 4
#define __SC_accept 5
#define __SC_getsockname 6
#define __SC_getpeername 7
#define __SC_socketpair 8
#define __SC_send 9
#define __SC_recv 10
#define __SC_sendto 11
#define __SC_recvfrom 12
#define __SC_shutdown 13
#define __SC_setsockopt 14
#define __SC_getsockopt 15
#define __SC_sendmsg 16
#define __SC_recvmsg 17
#define __SC_accept4 18
#define __SC_recvmmsg 19
#define __SC_sendmmsg 20

/* This is valid only because all socket syscalls are made via
 * socketcall, which always fills unused argument slots with zeros. */
#ifndef SYS_accept
#define SYS_accept SYS_accept4
#endif

#ifndef SO_RCVTIMEO_OLD
#define SO_RCVTIMEO_OLD 20
#endif
#ifndef SO_SNDTIMEO_OLD
#define SO_SNDTIMEO_OLD 21
#endif

#define SO_TIMESTAMP_OLD 29
#define SO_TIMESTAMPNS_OLD 35
#define SO_TIMESTAMPING_OLD 37
#define SCM_TIMESTAMP_OLD SO_TIMESTAMP_OLD
#define SCM_TIMESTAMPNS_OLD SO_TIMESTAMPNS_OLD
#define SCM_TIMESTAMPING_OLD SO_TIMESTAMPING_OLD

#ifndef SIOCGSTAMP_OLD
#define SIOCGSTAMP_OLD 0x8906
#endif
#ifndef SIOCGSTAMPNS_OLD
#define SIOCGSTAMPNS_OLD 0x8907
#endif

hidden void __procfdname(char __buf[static 15 + 3 * sizeof(int)], unsigned);

hidden void *__vdsosym(const char *, const char *);

#endif
