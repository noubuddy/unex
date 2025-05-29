#pragma once
#ifndef MEMORY_H
#define MEMORY_H

#include "core/types.h"

template <class Type>
class Allocator {
public:

    using ValueType = Type;

    ValueType* Allocate(const SIZE t_size) {
        return static_cast<ValueType*>(::operator new(t_size * sizeof(ValueType)));
    }

    void Deallocate(ValueType* t_ptr) {
        ::operator delete(t_ptr);
    }

};

#endif //MEMORY_H