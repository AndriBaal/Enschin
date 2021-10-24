#include <math.h>
#include "Vec2.h"
#include <algorithm>
#include <iterator>
#include <iostream>


class Matrix
{
private:
    static float length(float x, float y, float z);
public:
    /** Temporary memory for operations that need temporary matrix data. */
    static void multiply(float result[], float lhs[], float rhs[]);
    static void copyMatrix(float dest[], float src[], int size);
    static void translate(float m[], int mOffset, float x, float y, float z);
    static void rotate(float m[], int mOffset, float a, float x, float y, float z);
    static void setRotate(float rm[], int rmOffset, float a, float x, float y, float z);
    static void scale(float m[], int mOffset, float x, float y, float z);
    static void frustum(float m[], int offset, float left, float right, float bottom, float top, float near, float far);
    static void ortho(float m[], int offset, float left, float right, float bottom, float top, float near, float far);
    static void setLookAt(float rm[], int rmOffset,
        float eyeX, float eyeY, float eyeZ, 
        float centerX, float centerY, float centerZ, 
        float upX, float upY, float upZ);

    static void printMatrix(float matrix[]);
    static void printMatrixAsWurst(float matrix[]);
};