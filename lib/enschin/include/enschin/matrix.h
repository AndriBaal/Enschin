#pragma once

#include <string.h>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "vec2f.h"
#include "vec3f.h"

/**
 * @brief Matrix namespace that can handle matrices. No matrix
 * object required all float[] parameters should be float[16]
 * 
 */
namespace Matrix {
    float length(float x, float y, float z);

    void multiply(float result[16], float lhs[16], float rhs[16]);

    void copyMatrix(float dest[16], float src[16], int size);

    void translate(float m[16], Vec3f pos);

    void translate(float m[16], Vec2f pos, float z = 0.0f);

    void rotate(float m[16], float a = 0.0f, Vec3f axis = {0.0f, 0.0f, -1.0f});

    void setRotate(float rm[16], float a, Vec3f axis);

    void scale(float m[16], Vec3f scaling);

    void frustum(float m[16], float left, float right, float bottom, float top, float near, float far);

    void ortho(float m[16], float left, float right, float bottom, float top, float near, float far);

    void setLookAt(float rm[16], Vec3f eye, Vec3f center, Vec3f up);

    void printMatrix(float matrix[16]);

    void printMatrixAsWurst(float matrix[16]);
}