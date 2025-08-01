#ifndef _ARCA_SYS_LOG
#define _ARCA_SYS_LOG

void __libc_log_unimpl_syscall(const char *syscall);
#define LOG_UNIMPL(msg) __libc_log_unimpl_syscall(__FUNCTION__)

#endif
