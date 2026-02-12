#include "core/memory.h"

#include <cstdlib>

void* unex_memory__malloc(size_t t_size) {
    return malloc(t_size);
}

void unex_memory_free(void* t_ptr) {
    free(t_ptr);
}
