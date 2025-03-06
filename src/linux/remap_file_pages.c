#define _GNU_SOURCE
#include <sys/mman.h>
#include "syscall.h"

int remap_file_pages(void *addr, size_t size, int prot, size_t pgoff, int flags)
{
  // TODO (arca): remap_file_pages
  return -1;
}
