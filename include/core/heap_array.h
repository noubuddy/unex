#pragma once
#ifndef HEAP_ARRAY_H
#define HEAP_ARRAY_H

#include "core/basic_definitions.h"
#include "core/types.h"
#include "core/memory.h"

template <class Type, class Allocator = Allocator<Type>>
class HeapArray {

    #define ELEMENT_SIZE sizeof(Type)

    SIZE m_size = 0;
    SIZE m_capacity = 0;
    Type* m_data = nullptr;
    Type* m_cursor = nullptr;
    Allocator m_allocator;

public:

    HeapArray() {
    }

    HeapArray(const Allocator& t_allocator) {
    }

    HeapArray(const SIZE t_count, const Allocator& t_allocator = Allocator()) {
        m_data = m_allocator.Allocate(t_count);
        m_cursor = m_data;
        m_capacity = t_count;
    }

    HeapArray(const SIZE t_count, const Type& t_value, const Allocator& t_allocator = Allocator()) {
    }

    ~HeapArray() {
    }

public:

    NODISCARD FORCEINLINE SIZE GetSize() const { return m_size; }
    NODISCARD FORCEINLINE SIZE GetCapacity() const { return m_capacity; }
    FORCEINLINE Type* GetData() const { return m_data; }

public:

    Type& operator[] (const SIZE t_index) {
        return m_data[t_index * ELEMENT_SIZE];
    }

    const Type& operator[] (const SIZE t_index) const {
        return m_data[t_index * ELEMENT_SIZE];
    }

public:

    void Add(Type t_element) {
        m_data[m_size++] = t_element;
    }

    void Add(Type& t_element) {
        m_data[m_size++] = t_element;
    }

    void Resize(const SIZE t_count) {
    }

    void Resize(const SIZE t_count, const Type& t_value) {
    }

    void Reserve(const SIZE t_new_capacity) {
    }
};

#endif //HEAP_ARRAY_H
