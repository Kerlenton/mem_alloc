#include <assert.h>
#include "common.h"

void my_free(void *ptr) {
    if (!ptr) {
        return;
    }
    // TODO: consider merging blocks once splitting blocks is implemented
    struct block_meta *block_ptr = get_block_ptr(ptr);
    assert(block_ptr->free == 0);
    assert(block_ptr->magic == 0x77777777 || block_ptr->magic == 0x12345678);
    block_ptr->free = 1;
    block_ptr->magic = 0x55555555;
}
