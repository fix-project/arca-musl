#include <sys/ioctl.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <endian.h>
#include "syscall.h"

#define alignof(t) offsetof(struct { char c; t x; }, x)

#define W 1
#define R 2
#define WR 3

struct ioctl_compat_map {
	int new_req, old_req;
	unsigned char old_size, dir, force_align, noffs;
	unsigned char offsets[8];
};

#define NINTH(a,b,c,d,e,f,g,h,i,...) i
#define COUNT(...) NINTH(__VA_ARGS__,8,7,6,5,4,3,2,1,0)
#define OFFS(...) COUNT(__VA_ARGS__), { __VA_ARGS__ }

/* yields a type for a struct with original size n, with a misaligned
 * timeval/timespec expanded from 32- to 64-bit. for use with ioctl
 * number producing macros; only size of result is meaningful. */
#define new_misaligned(n) struct { int i; time_t t; char c[(n)-4]; }

struct v4l2_event {
	uint32_t a;
	uint64_t b[8];
	uint32_t c[2], ts[2], d[9];
};

int ioctl(int fd, int req, ...)
{
	void *arg;
	va_list ap;
	va_start(ap, req);
	arg = va_arg(ap, void *);
	va_end(ap);
	
	// TODO (arca): ioctl
	return -1;
}
