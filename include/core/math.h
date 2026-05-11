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

FORCEINLINE void unex_math_vec2_f32_create_3_params(s_unex_math_vec2_f32* t_vector, f32 t_x, f32 t_y) {
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


#define UNEX_DECLARE_MAT4(type, name) \
typedef struct { \
union { \
    type elements[16]; \
    struct { \
        type m00, m01, m02, m03, \
                m10, m11, m12, m13, \
                m20, m21, m22, m23, \
                m30, m31, m32, m33; \
    }; \
}; \
} name; \

UNEX_DECLARE_MAT4(FLOAT32, s_unex_math_mat4x4_f32)

FORCEINLINE void unex_math_mat4x4_f32_create(s_unex_math_mat4x4_f32* t_matrix) {
    t_matrix->m00 = 1.f; t_matrix->m01 = 0.f; t_matrix->m02 = 0.f; t_matrix->m03 = 0.f;
    t_matrix->m10 = 0.f; t_matrix->m11 = 1.f; t_matrix->m12 = 0.f; t_matrix->m13 = 0.f;
    t_matrix->m20 = 0.f; t_matrix->m21 = 0.f; t_matrix->m22 = 1.f; t_matrix->m23 = 0.f;
    t_matrix->m30 = 0.f; t_matrix->m31 = 0.f; t_matrix->m32 = 0.f; t_matrix->m33 = 1.f;
}

FORCEINLINE void unex_math_mat4x4_f32_add_mat4x4_f32(s_unex_math_mat4x4_f32* t_matrix1, s_unex_math_mat4x4_f32* t_matrix2) {
    for (int i = 0; i < 16; i++) {
        t_matrix1->elements[i] += t_matrix2->elements[i];
    }
}

FORCEINLINE void unex_math_mat4x4_f32_subtract_mat4x4_f32(s_unex_math_mat4x4_f32* t_matrix1, s_unex_math_mat4x4_f32* t_matrix2) {
    for (int i = 0; i < 16; i++) {
        t_matrix1->elements[i] -= t_matrix2->elements[i];
    }
}

FORCEINLINE void unex_math_mat4x4_f32_multiply_mat4x4_f32(s_unex_math_mat4x4_f32* t_result, s_unex_math_mat4x4_f32* t_matrix1, s_unex_math_mat4x4_f32* t_matrix2) {
    s_unex_math_mat4x4_f32 temp;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            temp.elements[i * 4 + j] =
                t_matrix1->elements[i * 4 + 0] * t_matrix2->elements[0 * 4 + j] +
                t_matrix1->elements[i * 4 + 1] * t_matrix2->elements[1 * 4 + j] +
                t_matrix1->elements[i * 4 + 2] * t_matrix2->elements[2 * 4 + j] +
                t_matrix1->elements[i * 4 + 3] * t_matrix2->elements[3 * 4 + j];
        }
    }
    *t_result = temp;
}

FORCEINLINE void unex_math_mat4x4_f32_multiply_vec3_f32(s_unex_math_vec3_f32* t_result, s_unex_math_mat4x4_f32* t_matrix, s_unex_math_vec3_f32* t_vector) {
    s_unex_math_vec3_f32 temp;
    temp.x = t_matrix->m00 * t_vector->x + t_matrix->m01 * t_vector->y + t_matrix->m02 * t_vector->z + t_matrix->m03;
    temp.y = t_matrix->m10 * t_vector->x + t_matrix->m11 * t_vector->y + t_matrix->m12 * t_vector->z + t_matrix->m13;
    temp.z = t_matrix->m20 * t_vector->x + t_matrix->m21 * t_vector->y + t_matrix->m22 * t_vector->z + t_matrix->m23;
    *t_result = temp;
}

#endif