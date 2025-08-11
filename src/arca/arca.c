#include <arca/arca.h>
#include <string.h>

void arca_log(const char *s)
{
	arca_debug_log((const uint8_t *)s, strlen(s));
}

void arca_log_int(const char *s, unsigned x)
{
	arca_debug_log_int((const uint8_t *)s, strlen(s), x);
}

void arca_log_ptr(const char *s, const void *x)
{
	arca_debug_log_int((const uint8_t *)s, strlen(s), (unsigned)x);
}

[[noreturn]] void arca_panic(const char *s)
{
	for (;;)
		__asm__("ud2");
}

arcad arca_blob_create_string(const char *s)
{
	return arca_blob_create((const uint8_t *)s, strlen(s));
}

arcad arca_symbolic_create_string(const char *s)
{
	return arca_function_create(false, arca_blob_create_string(s));
}
