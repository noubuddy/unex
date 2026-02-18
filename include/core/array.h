#pragma once
#include "core/memory.h"
#include "core/types.h"

typedef struct s_unex_array s_unex_array;

s_unex_array* unex_array_create(USIZE t_element_size, s_unex_allocator t_allocator);
void unex_array_destroy(s_unex_array* t_array);
USIZE unex_array_add(s_unex_array *t_array, void *t_element);
