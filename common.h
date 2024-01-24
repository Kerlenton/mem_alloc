#pragma once

#include <sys/types.h>

#define META_SIZE sizeof(struct block_meta)

extern void *global_base;

struct block_meta {
    size_t size;
    struct block_meta *next;
    int free;
    int magic; // for debugging only, TODO: remove this in non-debug mode
};

struct block_meta *get_block_ptr(void *ptr);
struct block_meta *request_space(struct block_meta *last, size_t size);
struct block_meta *find_free_block(struct block_meta **last, size_t size);
