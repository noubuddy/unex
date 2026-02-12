#include "core/array.h"

#include <stdlib.h>
#include "core/basic_definitions.h"

typedef struct {
    void* data;
    SIZE size;
    SIZE capacity;
    SIZE element_size;
    s_unex_allocator allocator;
} s_unex_control_block;

struct s_unex_array{
    s_unex_control_block* control_block;
};

static s_unex_control_block* unex_internal_control_block_init(const SIZE t_element_size, const s_unex_allocator t_allocator) {
    s_unex_control_block* cb = UNEX_ALLOC(sizeof(s_unex_control_block));
    if (cb == nullptr)
        return nullptr;

    cb->data = nullptr;
    cb->size = 0;
    cb->capacity = 0;
    cb->element_size = t_element_size;
    cb->allocator = t_allocator;

    return cb;
}

s_unex_array* unex_array_create(SIZE t_element_size, s_unex_allocator t_allocator) {
    s_unex_array* array = UNEX_ALLOC(sizeof(s_unex_array));
    if (array == nullptr)
        return nullptr;

    array->control_block = unex_internal_control_block_init(t_element_size, t_allocator);
    if (array->control_block == nullptr) {
        UNEX_FREE(array);
        return nullptr;
    }

    return array;
}

void unex_array_destroy(s_unex_array* t_array) {
    if (t_array == nullptr)
        return;

    s_unex_control_block* cb = t_array->control_block;
    if (cb != nullptr) {
        if (cb->data != nullptr) {
            cb->allocator.dealloc(cb->data);
        }
        UNEX_FREE(cb);
    }

    UNEX_FREE(t_array);
}

SIZE unex_array_add(s_unex_array* t_array, void* t_element) {
    UNEX_CHECK(t_array)

    if (t_array == nullptr)
        return -1;

    s_unex_control_block* cb = t_array->control_block;
    UNEX_CHECK(cb)

    if (cb == nullptr)
        return -1;

    if (cb->size <= cb->capacity) {

        cb->data = cb->allocator.alloc(cb->capacity);

        cb->size++;
        cb->capacity++;

    }
}
