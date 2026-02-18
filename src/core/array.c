#include "core/array.h"

#include <stdlib.h>
#include "core/basic_definitions.h"

typedef struct {
    void* data;
    USIZE size;
    USIZE capacity;
    USIZE element_size;
    s_unex_allocator allocator;
} s_unex_control_block;

struct s_unex_array{
    s_unex_control_block* control_block;
};

static s_unex_control_block* unex_internal_control_block_init(const USIZE t_element_size, const s_unex_allocator t_allocator) {
    s_unex_control_block* cb = (s_unex_control_block*)UNEX_ALLOC(sizeof(s_unex_control_block));
    if (cb == NULL)
        return NULL;

    cb->data = NULL;
    cb->size = 0;
    cb->capacity = 0;
    cb->element_size = t_element_size;
    cb->allocator = t_allocator;

    return cb;
}

s_unex_array* unex_array_create(USIZE t_element_size, s_unex_allocator t_allocator) {
    s_unex_array* array = (s_unex_array*)UNEX_ALLOC(sizeof(s_unex_array));
    if (array == NULL)
        return NULL;

    array->control_block = unex_internal_control_block_init(t_element_size, t_allocator);
    if (array->control_block == NULL) {
        UNEX_FREE(array);
        return NULL;
    }

    return array;
}

void unex_array_destroy(s_unex_array* t_array) {
    if (t_array == NULL)
        return;

    s_unex_control_block* cb = t_array->control_block;
    if (cb != NULL) {
        if (cb->data != NULL) {
            cb->allocator.dealloc(cb->data);
        }
        UNEX_FREE(cb);
    }

    UNEX_FREE(t_array);
}

USIZE unex_array_add(s_unex_array* t_array, void* t_element) {
    UNEX_CHECK(t_array)

    if (t_array == NULL)
        return -1;

    s_unex_control_block* cb = t_array->control_block;
    UNEX_CHECK(cb)

    if (cb == NULL)
        return -1;

    if (cb->size <= cb->capacity) {

        cb->data = cb->allocator.alloc(cb->capacity);

        cb->size++;
        cb->capacity++;

    }
}
