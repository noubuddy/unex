#pragma once
#ifndef UNEX_CPP_TYPES_H
#define UNEX_CPP_TYPES_H

#include <memory>

template <typename T>
using SharedPtr = std::shared_ptr<T>;

template <typename T>
using UniquePtr = std::unique_ptr<T>;

#endif