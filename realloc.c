#include <string.h>

#include "free.h"
#include "common.h"
#include "malloc.h"

void *my_realloc(void *ptr, size_t size) {
    if (!ptr) {
        // realloc should act like malloc
        return my_malloc(size);
    }
    struct block_meta *block_ptr = get_block_ptr(ptr);
    if (block_ptr->size >= size) {
        // we have enough space, could free some once we implement split
        return ptr;
    }
    // need to really realloc, malloc new space and free old space,
    // then copy old data to new space
    void *new_ptr;
    new_ptr = my_malloc(size);
    if (!new_ptr) {
        return NULL; // TODO: set errno on failure
    }
    memcpy(new_ptr, ptr, block_ptr->size);
    my_free(ptr);
    return new_ptr;
}
