#include "Matrix.h"

namespace Matrix {

    float length(float x, float y, float z) {
        return (float)sqrt(x * x + y * y + z * z);
    }

    void multiply(float result[], float lhs[],  float rhs[]) {
        float lhsc[16], rhsc[16] = {};
        copyMatrix(lhsc, lhs, 16);
        copyMatrix(rhsc, rhs, 16);
        for (int i = 0; i < 16; i+= 4) {
            for(int j = 0; j < 4; j++) {
                result[i+j] = lhsc[i] * rhsc[j] +
                            lhsc[i+1] * rhsc[4+j] +
                            lhsc[i+2] * rhsc[8+j] +
                            lhsc[i+3] * rhsc[12+j];
            }
        }
    }

    void copyMatrix(float dest[], float src[], int size) {
        for (int i = 0; i < size; i++) {
            dest[i] = src[i];
        }
    }

    void translate(float m[], Vec3 loc) {
        for (int i=0 ; i<4 ; i++) {
            m[12 + i] += m[i] * loc.x + m[4 + i] * loc.y + m[8 + i] * loc.z;
        }
    }

    void translate(float m[], Vec2 loc, float z) {
        for (int i=0 ; i<4 ; i++) {
            m[12 + i] += m[i] * loc.x + m[4 + i] * loc.y + m[8 + i] * z;
        }
    }


    void rotate(float m[], float a, float x, float y, float z) {
        float sTemp[16] = {0.0f};
        setRotate(sTemp, a, x, y, z);
        multiply(sTemp, sTemp, m);
        for (int i = 0; i < 16; i++) {
            m[i] = sTemp[i];
        }
    }

    void setRotate(float rm[], float a, float x, float y, float z) {
        rm[3] = 0;
        rm[7] = 0;
        rm[11]= 0;
        rm[12]= 0;
        rm[13]= 0;
        rm[14]= 0;
        rm[15]= 1;
        a *= (float) (M_PI / 180.0f);
        float s = (float) sin(a);
        float c = (float) cos(a);
        if (1.0f == x && 0.0f == y && 0.0f == z) {
            rm[5] = c;   rm[10]= c;
            rm[6] = s;   rm[9] = -s;
            rm[1] = 0;   rm[2] = 0;
            rm[4] = 0;   rm[8] = 0;
            rm[0] = 1;
        } else if (0.0f == x && 1.0f == y && 0.0f == z) {
            rm[0] = c;   rm[10]= c;
            rm[8] = s;   rm[2] = -s;
            rm[1] = 0;   rm[4] = 0;
            rm[6] = 0;   rm[9] = 0;
            rm[5] = 1;
        } else if (0.0f == x && 0.0f == y && 1.0f == z) {
            rm[0] = c;   rm[5] = c;
            rm[1] = s;   rm[4] = -s;
            rm[2] = 0;   rm[6] = 0;
            rm[8] = 0;   rm[9] = 0;
            rm[10]= 1;
        } else {
            float len = length(x, y, z);
            if (1.0f != len) {
                float recipLen = 1.0f / len;
                x *= recipLen;
                y *= recipLen;
                z *= recipLen;
            }
            float nc = 1.0f - c;
            float xy = x * y;
            float yz = y * z;
            float zx = z * x;
            float xs = x * s;
            float ys = y * s;
            float zs = z * s;
            rm[0] = x*x*nc +  c;
            rm[4] =  xy*nc - zs;
            rm[8] =  zx*nc + ys;
            rm[1] =  xy*nc + zs;
            rm[5] = y*y*nc +  c;
            rm[9] =  yz*nc - xs;
            rm[2] =  zx*nc - ys;
            rm[6] =  yz*nc + xs;
            rm[10] = z*z*nc +  c;
        }
    }

    void scale(float m[], float x, float y, float z) {
        for (int i=0 ; i<4 ; i++)  {
            int mi = + i;
            m[     mi] *= x;
            m[ 4 + mi] *= y;
            m[ 8 + mi] *= z;
        }
    }

    void frustum(float m[], float left, float right, float bottom, float top, float near, float far) {
        float r_width  = 1.0f / (right - left);
        float r_height = 1.0f / (top - bottom);
        float r_depth  = 1.0f / (near - far);
        float x = 2.0f * (near * r_width);
        float y = 2.0f * (near * r_height);
        float A = (right + left) * r_width;
        float B = (top + bottom) * r_height;
        float C = (far + near) * r_depth;
        float D = 2.0f * (far * near * r_depth);
        m[0] = x;
        m[5] = y;
        m[8] = A;
        m[ 9] = B;
        m[10] = C;
        m[14] = D;
        m[11] = -1.0f;
        m[ 1] = 0.0f;
        m[ 2] = 0.0f;
        m[ 3] = 0.0f;
        m[ 4] = 0.0f;
        m[ 6] = 0.0f;
        m[ 7] = 0.0f;
        m[12] = 0.0f;
        m[13] = 0.0f;
        m[15] = 0.0f;
    }

    void ortho(float m[], float left, float right, float bottom, float top, float near, float far) {
        const float r_width  = 1.0f / (right - left);
        const float r_height = 1.0f / (top - bottom);
        const float r_depth  = 1.0f / (far - near);
        const float x =  2.0f * (r_width);
        const float y =  2.0f * (r_height);
        const float z = -2.0f * (r_depth);
        const float tx = -(right + left) * r_width;
        const float ty = -(top + bottom) * r_height;
        const float tz = -(far + near) * r_depth;
        m[0] = x;
        m[5] = y;
        m[10] = z;
        m[12] = tx;
        m[13] = ty;
        m[14] = tz;
        m[15] = 1.0f;
        m[1] = 0.0f;
        m[2] = 0.0f;
        m[3] = 0.0f;
        m[4] = 0.0f;
        m[6] = 0.0f;
        m[7] = 0.0f;
        m[8] = 0.0f;
        m[9] = 0.0f;
        m[11] = 0.0f;
    }

    void setLookAt(float rm[],
        float eyeX, float eyeY, float eyeZ, 
        float centerX, float centerY, float centerZ, 
        float upX, float upY, float upZ) {
        // See the OpenGL GLUT documentation for gluLookAt for a description
        // of the algorithm. We implement it in a straightforward way:
        float fx = centerX - eyeX;
        float fy = centerY - eyeY;
        float fz = centerZ - eyeZ;
        // Normalize f
        float rlf = 1.0f / length(fx, fy, fz);
        fx *= rlf;
        fy *= rlf;
        fz *= rlf;
        // compute s = f x up (x means "cross product")
        float sx = fy * upZ - fz * upY;
        float sy = fz * upX - fx * upZ;
        float sz = fx * upY - fy * upX;
        // and normalize s
        float rls = 1.0f / length(sx, sy, sz);
        sx *= rls;
        sy *= rls;
        sz *= rls;
        // compute u = s x f
        float ux = sy * fz - sz * fy;
        float uy = sz * fx - sx * fz;
        float uz = sx * fy - sy * fx;
        rm[0] = sx;
        rm[1] = ux;
        rm[2] = -fx;
        rm[3] = 0.0f;
        rm[4] = sy;
        rm[5] = uy;
        rm[6] = -fy;
        rm[7] = 0.0f;
        rm[8] = sz;
        rm[9] = uz;
        rm[10] = -fz;
        rm[11] = 0.0f;
        rm[12] = 0.0f;
        rm[13] = 0.0f;
        rm[14] = 0.0f;
        rm[15] = 1.0f;
        translate(rm, {-eyeX, -eyeY, -eyeZ});
    }

    void printMatrix(float matrix[]) {
        std::cout << "Matrix: " << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout
            << matrix[i*4] << "\t"
            << matrix[i*4+1] << "\t"
            << matrix[i*4+2] << "\t"
            << matrix[i*4+3] << "\t"
            << std::endl;
        }
    }

    void printMatrixAsWurst(float matrix[]) {
        std::cout << "Matrix as Wurst: " << std::endl;
        for (int i = 0; i < 16; i++) {
            std::cout << " " << matrix[i];
        }
        std::cout << std::endl;
    }
}