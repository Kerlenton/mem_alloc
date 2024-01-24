#include <unistd.h>

#include "common.h"

void *my_malloc(size_t size) {
    struct block_meta *block;
    // TODO: align size?
    if (size <= 0) {
        return NULL;
    }
    if (!global_base) { // first call
        block = request_space(NULL, size);
        if (!block) {
            return NULL;
        }
        global_base = block;
    } else {
        struct block_meta *last = global_base;
        block = find_free_block(&last, size);
        if (!block) { // failed to find free block
            block = request_space(last, size);
            if (!block) {
                return NULL;
            }
        } else { // found free block
            // TODO: consider splitting block here
            block->free = 0;
            block->magic = 0x77777777;
        }
    }
    return (block + 1);
}
