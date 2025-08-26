#include "arca/asm.h"
#include "arca/sys.h"
#include <arca/arca.h>
#include <arca/io.h>

int __sys_isatty(int fd)
{
	// TODO(arca): add effect for detecting TTY
	return 1;
}

int __sys_open(const char *path, int flags, mode_t mode)
{
	arcad f = arca_symbolic_create_string("open");
	f = arca_function_apply(f, arca_blob_create_string(path));
	f = arca_function_apply(f, arca_word_create(flags));
	f = arca_function_apply(f, arca_word_create(mode));
	arca_call_with_current_continuation(f);
	// TODO (Arca): handle errors
	arcad r = arca_argument();
	uint64_t count;
	arca_word_read(r, &count);
	arca_drop(r);
	return count;
}

weak_alias(__sys_open, __sys_open_cp);

int __sys_close(int fd)
{
	arcad f = arca_symbolic_create_string("close");
	f = arca_function_apply(f, arca_word_create(fd));
	arca_call_with_current_continuation(f);
	// TODO (Arca): handle errors
	arcad r = arca_argument();
	uint64_t retval;
	arca_word_read(r, &retval);
	arca_drop(r);
	return retval;
}

weak_alias(__sys_close, __sys_close_cp);

ssize_t __sys_read(int fd, void *buf, size_t count)
{
	arcad f = arca_symbolic_create_string("read");
	f = arca_function_apply(f, arca_word_create(fd));
	f = arca_function_apply(f, arca_word_create(count));
	arca_call_with_current_continuation(f);
	// TODO (Arca): handle errors
	arcad r = arca_argument();
	if (arca_type(r) == __TYPE_blob) {
		size_t x = arca_blob_read(r, 0, (uint8_t *)buf, count);
		arca_drop(r);
		return x;
	} else if (arca_type(r) == __TYPE_word) {
		uint64_t err;
		arca_word_read(r, &err);
		arca_drop(r);
		return err;
	} else {
		arca_panic("invalid return type from read effect");
	}
}

weak_alias(__sys_read, __sys_read_cp);

ssize_t __sys_readv(int fd, const struct iovec *iov, int iovcnt)
{
	arca_panic("sys_readv");
}

ssize_t __sys_writev(int fd, const struct iovec *iov, int iovcnt)
{
	ssize_t bytes_written = 0;
	for (size_t i = 0; i < iovcnt; i++) {
		const struct iovec v = iov[i];
		arcad f = arca_symbolic_create_string("write");
		f = arca_function_apply(f, arca_word_create(fd));
		f = arca_function_apply(
		    f, arca_blob_create(v.iov_base, v.iov_len));
		arca_call_with_current_continuation(f);
		// TODO (Arca): handle errors
		arcad r = arca_argument();
		uint64_t count;
		arca_word_read(r, &count);
		arca_drop(r);
		bytes_written += count;
	}
	return bytes_written;
}

[[noreturn]] void __sys_exit_group(int status)
{
	// TODO (Arca): correctly implement exit group
	__sys_exit(status);
}

[[noreturn]] void __sys_exit(int status)
{
	for (;;) {
		arcad f = arca_symbolic_create_string("exit");
		f = arca_function_apply(f, arca_word_create(status));
		arca_call_with_current_continuation(f);
	}
}

int __sys_fsync(int fd)
{
	(void)fd;
	return 0;
}

off_t __sys_lseek(int fd, off_t offset, int whence)
{
	arcad f = arca_symbolic_create_string("seek");
	f = arca_function_apply(f, arca_word_create(fd));
	f = arca_function_apply(f, arca_word_create(offset));
	f = arca_function_apply(f, arca_word_create(whence));
	arca_call_with_current_continuation(f);
	// TODO (Arca): handle errors
	arcad r = arca_argument();
	uint64_t count;
	arca_word_read(r, &count);
	arca_drop(r);
	return count;
}
