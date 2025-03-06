#include "pthread_impl.h"
#include "atomic.h"
#include "syscall.h"
/* cheat and reuse CRTJMP macro from dynlink code */
#include "dynlink.h"

static void *unmap_base;
static size_t unmap_size;
static char shared_stack[256];

void __unmapself(void *base, size_t size)
{
	// TODO (arca): __unmapself
}
