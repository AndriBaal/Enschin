#include <math.h>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "Vec2.h"
#include "Vec3.h"

namespace Matrix {
    float length(float x, float y, float z);
    void multiply(float result[], float lhs[], float rhs[]);
    void copyMatrix(float dest[], float src[], int size);
    void translate(float m[], Vec3 loc);
    void translate(float m[], Vec2 loc, float z = 0.0f);
    void rotate(float m[], float a, float x, float y, float z);
    void setRotate(float rm[], float a, float x, float y, float z);
    void scale(float m[], float x, float y, float z);
    void frustum(float m[], float left, float right, float bottom, float top, float near, float far);
    void ortho(float m[], float left, float right, float bottom, float top, float near, float far);
    void setLookAt(float rm[],
        float eyeX, float eyeY, float eyeZ, 
        float centerX, float centerY, float centerZ, 
        float upX, float upY, float upZ);

    void printMatrix(float matrix[]);
    void printMatrixAsWurst(float matrix[]);
};