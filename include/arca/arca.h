#ifndef _ARCA_ARCA_H
#define _ARCA_ARCA_H

#include <arca/sys.h>

void arca_log(const char *s);
void arca_log_int(const char *s, unsigned x);
void arca_log_ptr(const char *s, const void *x);
[[noreturn]] void arca_panic(const char *s);

arcad arca_blob_create_string(const char *s);
arcad arca_symbolic_create_string(const char *s);

#endif
