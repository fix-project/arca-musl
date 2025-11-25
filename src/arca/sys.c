#include <arca/arca.h>
#include "arca/asm.h"
#include "syscall_arch.h"

#ifndef __scc
#define __scc(X) ((uint64_t)(X))
typedef uint64_t syscall_arg_t;
#endif

#define __syscall1(n, a) __syscall1(n, __scc(a))
#define __syscall2(n, a, b) __syscall2(n, __scc(a), __scc(b))
#define __syscall3(n, a, b, c) __syscall3(n, __scc(a), __scc(b), __scc(c))
#define __syscall4(n, a, b, c, d)                                              \
	__syscall4(n, __scc(a), __scc(b), __scc(c), __scc(d))
#define __syscall5(n, a, b, c, d, e)                                           \
	__syscall5(n, __scc(a), __scc(b), __scc(c), __scc(d), __scc(e))
#define __syscall6(n, a, b, c, d, e, f)                                        \
	__syscall6(n, __scc(a), __scc(b), __scc(c), __scc(d), __scc(e),        \
	           __scc(f))
#define __syscall7(n, a, b, c, d, e, f, g)                                     \
	__syscall7(n, __scc(a), __scc(b), __scc(c), __scc(d), __scc(e),        \
	           __scc(f), __scc(g))

#define __SYSCALL_NARGS_X(a, b, c, d, e, f, g, h, n, ...) n
#define __SYSCALL_NARGS(...)                                                   \
	__SYSCALL_NARGS_X(__VA_ARGS__, 7, 6, 5, 4, 3, 2, 1, 0, )
#define __SYSCALL_CONCAT_X(a, b) a##b
#define __SYSCALL_CONCAT(a, b) __SYSCALL_CONCAT_X(a, b)
#define __SYSCALL_DISP(b, ...)                                                 \
	__SYSCALL_CONCAT(b, __SYSCALL_NARGS(__VA_ARGS__))(__VA_ARGS__)

#define syscall(...) __SYSCALL_DISP(__syscall, __VA_ARGS__)

[[noreturn]] static void ud2()
{
	for (;;) {
		__asm__("ud2");
	}
}

void arca_nop(void)
{
	syscall(__NR_nop);
}

arcad arca_clone(arcad value)
{
	return syscall(__NR_clone, value);
}

int64_t arca_drop(arcad value)
{
	return syscall(__NR_drop, value);
}

[[noreturn]] void arca_exit(arcad value)
{
	syscall(__NR_exit, value);
	ud2();
}

arcad arca_argument(void)
{
	return syscall(__NR_get_argument);
}

int64_t arca_type(arcad value)
{
	return syscall(__NR_type, value);
}

arcad arca_null_create(void)
{
	return syscall(__NR_create_null);
}

arcad arca_word_create(uint64_t value)
{
	return syscall(__NR_create_word, value);
}

arcad arca_blob_create(const uint8_t *data, size_t len)
{
	return syscall(__NR_create_blob, data, len);
}

arcad arca_tuple_create(size_t len)
{
	return syscall(__NR_create_tree, len);
}

arcad arca_page_create(size_t size)
{
	return syscall(__NR_create_page, size);
}

arcad arca_table_create(size_t size)
{
	return syscall(__NR_create_table, size);
}

arcad arca_function_create(arcad data)
{
	return syscall(__NR_create_function, data);
}

arcad arca_word_read(arcad word, uint64_t *output)
{
	return syscall(__NR_read, word, output);
}

arcad arca_blob_read(arcad blob, size_t offset, uint8_t *data, size_t len)
{
	return syscall(__NR_read, blob, offset, data, len);
}

arcad arca_page_read(arcad page, size_t offset, uint8_t *data, size_t len)
{
	return syscall(__NR_read, page, offset, data, len);
}

arcad arca_page_write(arcad page, size_t offset, const uint8_t *data,
                      size_t len)
{
	return syscall(__NR_write, page, offset, data, len);
}

int64_t arca_equals(arcad x, arcad y)
{
	return syscall(__NR_equals, x, y);
}

int64_t arca_length(arcad value, size_t *output)
{
	return syscall(__NR_length, value, output);
}

arcad arca_tuple_get(arcad value, size_t index)
{
	return syscall(__NR_get, value, index);
}

arcad arca_table_get(arcad table, size_t index, struct arca_entry *entry)
{
	return syscall(__NR_get, table, index, entry);
}

int64_t arca_tuple_set(arcad tuple, size_t index, arcad value)
{
	return syscall(__NR_set, tuple, index, value);
}

int64_t arca_table_set(arcad table, size_t index,
                       const struct arca_entry *entry)
{
	return syscall(__NR_set, table, index, entry);
}

arcad arca_function_apply(arcad target, arcad argument)
{
	return syscall(__NR_apply, target, argument);
}

int64_t arca_table_map(arcad table, void *address, struct arca_entry *entry)
{
	return syscall(__NR_map, table, address, entry);
}

int64_t arca_mmap(void *address, struct arca_entry *entry)
{
	return syscall(__NR_mmap, address, entry);
}

int64_t arca_mprotect(void *address, int mode)
{
	return syscall(__NR_mprotect, address, mode);
}

int64_t arca_compat_mmap(void *address, size_t size, unsigned mode)
{
	return syscall(__NR_compat_mmap, address, size, mode);
}

arcad arca_call_with_current_continuation(arcad value)
{
	return syscall(__NR_call_with_current_continuation, value);
}

arcad arca_get_continuation(void)
{
	return syscall(__NR_get_continuation);
}

int64_t arca_debug_log(const uint8_t *message, size_t len)
{
	return syscall(__NR_debug_log, message, len);
}

int64_t arca_debug_log_int(const uint8_t *message, size_t len, uint64_t value)
{
	return syscall(__NR_debug_log_int, message, len, value);
}

int64_t arca_debug_show(const uint8_t *message, size_t len, arcad value)
{
	return syscall(__NR_debug_show, message, len, value);
}
