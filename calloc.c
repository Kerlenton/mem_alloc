#include <string.h>
#include <sys/types.h>

#include "malloc.h"

void *calloc(size_t nelem, size_t elsize) {
    size_t size = nelem * elsize; // TODO: check for overflow.
    void *ptr = my_malloc(size);
    memset(ptr, 0, size);
    return ptr;
}
