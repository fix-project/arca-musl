#define _GNU_SOURCE
#include <sys/stat.h>
#include <string.h>
#include <syscall.h>
#include <sys/sysmacros.h>
#include <errno.h>

int statx(int dirfd, const char *restrict path, int flags, unsigned mask, struct statx *restrict stx)
{
	// TODO (arca): statx
	return -1;
}
