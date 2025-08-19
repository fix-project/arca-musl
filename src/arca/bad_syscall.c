#include <arca/arca.h>

[[noreturn]] int bad_syscall(const char *file, const char *function,
                             const char *syscall)
{
	arca_log("libc tried to make Linux system call!");
	arca_log(file);
	arca_log(function);
	arca_panic(syscall);
}
