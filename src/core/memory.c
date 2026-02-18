#include "core/memory.h"

#include <cstdlib>

void* unex_memory_malloc(size_t t_size) {
    return malloc(t_size);
}

void* unex_memory_malloc_aligned(size_t t_size, size_t t_align) {
    return _aligned_malloc(t_size, t_align);
}

void unex_memory_free(void* t_ptr) {
    free(t_ptr);
}

void* unex_memory_realloc(void *t_ptr, size_t t_size) {
    return realloc(t_ptr, t_size);
}
