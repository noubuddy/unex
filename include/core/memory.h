#pragma once
#include "core/types.h"

#define UNEX_ALLOC(size) unex_memory_malloc(size)
#define UNEX_FREE(ptr) unex_memory_free(ptr)
#define UNEX_REALLOC(ptr, size) unex_memory__realloc(ptr, size)

typedef struct s_unex_allocator {
    void* (*alloc)(USIZE t_size);
    void  (*dealloc)(void* t_ptr);
    void*  (*realloc)(void* t_ptr, USIZE t_size);
} s_unex_allocator;

void* unex_memory_malloc(USIZE t_size);
void* unex_memory_malloc_aligned(USIZE t_size, USIZE t_align);
void unex_memory_free(void* t_ptr);
void* unex_memory_realloc(void* t_ptr, USIZE t_size);

static constexpr s_unex_allocator g_unex_allocator = { unex_memory_malloc, unex_memory_free, unex_memory_realloc };