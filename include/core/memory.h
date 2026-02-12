#pragma once
#include "core/types.h"

#define UNEX_ALLOC(size) unex_memory__malloc(size)
#define UNEX_FREE(ptr) unex_memory_free(ptr)

typedef struct s_unex_allocator {
    void* (*alloc)(SIZE t_size);
    void  (*dealloc)(void* t_ptr);
} s_unex_allocator;

void* unex_memory__malloc(SIZE t_size);
void unex_memory_free(void* t_ptr);

static const s_unex_allocator g_unex_allocator = { unex_memory__malloc, unex_memory_free };