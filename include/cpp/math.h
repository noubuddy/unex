#pragma once
#ifndef UNEX_CPP_MATH_H
#define UNEX_CPP_MATH_H

#include "core/math.h"

namespace math {
    struct vec3f32 {
        union {
            s_unex_math_vec3_f32 vector;
            struct {
                FLOAT32 x, y, z;
            };
        };

    public:
        vec3f32() {
            unex_math_vec3_f32_create(&vector);
        }

        vec3f32(FLOAT32 t_value = 0.0f) {
            unex_math_vec3_f32_create_1_param(&vector, t_value);
        }

        vec3f32(FLOAT32 t_x = 0.0f, FLOAT32 t_y = 0.0f, FLOAT32 t_z = 0.0f) {
            unex_math_vec3_f32_create_3_params(&vector, t_x, t_y, t_z);
        }

        vec3f32 operator+=(FLOAT32 t_value) {
            unex_math_vec3_f32_add_f32(&vector, t_value);
            return *this;
        }

        // vec3f32 operator+=(glm::vec3 t_value)
        // {
        //     return {this->x + t_value.x, this->y + t_value.y, this->z + t_value.z};
        // }
    };

    struct vec2f32 {
        FLOAT32 x, y;

        vec2f32() {
            x = 0.0f;
            y = 0.0f;
        }

        vec2f32(FLOAT32 t_x, FLOAT32 t_y) : x(t_x), y(t_y) {
        }

        vec2f32 operator+=(FLOAT32 t_value) const {
            return {this->x + t_value, this->y + t_value};
        }

        vec2f32 operator+=(glm::vec3 t_value) const {
            return {this->x + t_value.x, this->y + t_value.y};
        }
    };

    struct mat4x4f32 {
        FLOAT32 _11, _12, _13, _14;
        FLOAT32 _21, _22, _23, _24;
        FLOAT32 _31, _32, _33, _34;
        FLOAT32 _41, _42, _43, _44;
    };
}

#endif
