#include <arca/log.h>
#include <arca/arca.h>

void __libc_log_unimpl_syscall(const char *syscall)
{
	arca_log("have unimplemented system call:");
	arca_log(syscall);
}
