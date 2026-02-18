#pragma once
#ifndef UNEX_MATH_H
#define UNEX_MATH_H

#include "core/types.h"
#include "basic_definitions.h"

// --- VEC3 START --- //
#define UNEX_DECLARE_VEC3(type, name) \
typedef struct {                             \
    type x, y, z;                            \
} name;                                      \

UNEX_DECLARE_VEC3(FLOAT32, s_unex_math_vec3_f32)

FORCEINLINE void unex_math_vec3_f32_create(s_unex_math_vec3_f32* t_vector) {
    t_vector->x = 0.f;
    t_vector->y = 0.f;
    t_vector->z = 0.f;
}

FORCEINLINE void unex_math_vec3_f32_create_1_param(s_unex_math_vec3_f32* t_vector, f32 t_value) {
    t_vector->x = t_value;
    t_vector->y = t_value;
    t_vector->z = t_value;
}

FORCEINLINE void unex_math_vec3_f32_create_3_params(s_unex_math_vec3_f32* t_vector, f32 t_x, f32 t_y, f32 t_z) {
    t_vector->x = t_x;
    t_vector->y = t_y;
    t_vector->z = t_z;
}

FORCEINLINE void unex_math_vec3_f32_add_vec3_f32(s_unex_math_vec3_f32* t_vector1, s_unex_math_vec3_f32* t_vector2) {
    t_vector1->x += t_vector2->x;
    t_vector1->y += t_vector2->y;
    t_vector1->z += t_vector2->z;
}

FORCEINLINE void unex_math_vec3_f32_add_f32(s_unex_math_vec3_f32* t_vector, f32 t_value) {
    t_vector->x += t_value;
    t_vector->y += t_value;
    t_vector->z += t_value;
}

FORCEINLINE void unex_math_vec3_f32_subtract(s_unex_math_vec3_f32* t_vector1, s_unex_math_vec3_f32* t_vector2) {
    t_vector1->x -= t_vector2->x;
    t_vector1->y -= t_vector2->y;
    t_vector1->z -= t_vector2->z;
}
// --- VEC3 END --- //

// --- VEC2 START --- //

#define UNEX_DECLARE_VEC2(type, name) \
typedef struct {                             \
type x, y;                            \
} name;                                      \

UNEX_DECLARE_VEC2(FLOAT32, s_unex_math_vec2_f32)

FORCEINLINE void unex_math_vec2_f32_create(s_unex_math_vec2_f32* t_vector) {
    t_vector->x = 0.f;
    t_vector->y = 0.f;
}

FORCEINLINE void unex_math_vec2_f32_create_1_param(s_unex_math_vec2_f32* t_vector, f32 t_value) {
    t_vector->x = t_value;
    t_vector->y = t_value;
}

FORCEINLINE void unex_math_vec2_f32_create_3_params(s_unex_math_vec2_f32* t_vector, f32 t_x, f32 t_y, f32 t_z) {
    t_vector->x = t_x;
    t_vector->y = t_y;
}

FORCEINLINE void unex_math_vec2_f32_add_vec3_f32(s_unex_math_vec2_f32* t_vector1, s_unex_math_vec2_f32* t_vector2) {
    t_vector1->x += t_vector2->x;
    t_vector1->y += t_vector2->y;
}

FORCEINLINE void unex_math_vec2_f32_add_f32(s_unex_math_vec2_f32* t_vector, f32 t_value) {
    t_vector->x += t_value;
    t_vector->y += t_value;
}

FORCEINLINE void unex_math_vec2_f32_subtract(s_unex_math_vec2_f32* t_vector1, s_unex_math_vec2_f32* t_vector2) {
    t_vector1->x -= t_vector2->x;
    t_vector1->y -= t_vector2->y;
}

// --- VEC2 END --- //


#endif