#include <enschin/matrix.h>

namespace Matrix {

    /**
     * @brief Comput the size of 3 float
     * 
     * @return float Size in float
     */
    float length(Vec3f v) {
        return (float)sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    }

    /**
     * @brief Multiply two 4x4 Matrices.
     * 
     * @param result Array that the result gets written in to
     * @param lhs Lefthand array
     * @param rhs Righthand array
     */
    void multiply(float result[16], float lhs[16],  float rhs[16]) {
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

    /**
     * @brief Copy Matrix intro the destination array
     * 
     * @param dest Destination array
     * @param src Source array
     * @param size Size of the arrays
     */
    void copyMatrix(float dest[16], float src[16], int size) {
        for (int i = 0; i < size; i++) {
            dest[i] = src[i];
        }
    }

    /**
     * @brief Translate the matrix to a specifix position
     * 
     * @param m Matrix
     * @param pos Location
     */
    void translate(float m[], Vec3f pos) {
        for (int i=0 ; i<4 ; i++) {
            m[12 + i] += m[i] * pos.x + m[4 + i] * pos.y + m[8 + i] * pos.z;
        }
    }

    
    /**
     * @brief Translate the matrix to a specifix position
     * 
     * @param m Matrix
     * @param pos Location on x, y
     * @param z Z location (default=0.0f)
     */
    void translate(float m[], Vec2f pos, float z) {
        for (int i=0 ; i<4 ; i++) {
            m[12 + i] += m[i] * pos.x + m[4 + i] * pos.y + m[8 + i] * z;
        }
    }

    /**
     * @brief Rotate the matrix 
     * 
     * @param m Matrix
     * @param a Angle in degree
     * @param x x axis (default=0.0f)
     * @param y y axis (default=0.0f)
     * @param z z axis (default=0.0f)
     */
    void rotate(float m[], float a, Vec3f axis) {
        float sTemp[16] = {0.0f};
        setRotate(sTemp, a, axis);
        multiply(sTemp, sTemp, m);
        for (int i = 0; i < 16; i++) {
            m[i] = sTemp[i];
        }
    }

    /**
     * @brief Set the Rotation of a matrix.
     * 
     * @param rm Matrix
     * @param a Angle
     * @param axis Axis
     */
    void setRotate(float rm[], float a, Vec3f axis) {
        rm[3] = 0;
        rm[7] = 0;
        rm[11]= 0;
        rm[12]= 0;
        rm[13]= 0;
        rm[14]= 0;
        rm[15]= 1;
        a *= (float) (3.14159265358979323846 / 180.0f);
        float s = (float) sin(a);
        float c = (float) cos(a);
        if (Vec3f(1.0f, 0.0f, 0.0f) == axis) {
            rm[5] = c;   rm[10]= c;
            rm[6] = s;   rm[9] = -s;
            rm[1] = 0;   rm[2] = 0;
            rm[4] = 0;   rm[8] = 0;
            rm[0] = 1;
        } else if (Vec3f(0.0f, 1.0f, 0.0f) == axis) {
            rm[0] = c;   rm[10]= c;
            rm[8] = s;   rm[2] = -s;
            rm[1] = 0;   rm[4] = 0;
            rm[6] = 0;   rm[9] = 0;
            rm[5] = 1;
        } else if (Vec3f(0.0f, 0.0f, 1.0f) == axis) {
            rm[0] = c;   rm[5] = c;
            rm[1] = s;   rm[4] = -s;
            rm[2] = 0;   rm[6] = 0;
            rm[8] = 0;   rm[9] = 0;
            rm[10]= 1;
        } else {
            float len = length(axis);
            if (1.0f != len) {
                float recipLen = 1.0f / len;
                axis *= recipLen;
            }
            float nc = 1.0f - c;
            float xy = axis.x * axis.y;
            float yz = axis.y * axis.z;
            float zx = axis.z * axis.x;
            float xs = axis.x * s;
            float ys = axis.y * s;
            float zs = axis.z * s;
            rm[0] = axis.x*axis.x*nc +  c;
            rm[4] =  xy*nc - zs;
            rm[8] =  zx*nc + ys;
            rm[1] =  xy*nc + zs;
            rm[5] = axis.y*axis.y*nc +  c;
            rm[9] =  yz*nc - xs;
            rm[2] =  zx*nc - ys;
            rm[6] =  yz*nc + xs;
            rm[10] = axis.z*axis.z*nc +  c;
        }
    }

    /**
     * @brief Scale the given Matrix
     * 
     * @param m Matrix to be scaled
     * @param x Scale on the x-axis
     * @param y Scale on the y-axis
     * @param z Scale on the z-axis
     */
    void scale(float m[], Vec3f scaling) {
        for (int i=0 ; i<4 ; i++)  {
            int mi = + i;
            m[     mi] *= scaling.x;
            m[ 4 + mi] *= scaling.y;
            m[ 8 + mi] *= scaling.z;
        }
    }

    /**
     * @brief Set the boundries of a matrix.
     * 
     * @param m Matrix
     * @param left Left of the matrix
     * @param right Right of the matrix
     * @param bottom Bottom of the matrix
     * @param top Top of the matrix
     * @param near Near
     * @param far Far
     */
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

    /**
     * @brief Set the boundries of a matrix.
     * 
     * @param m Matrix
     * @param left Left of the matrix
     * @param right Right of the matrix
     * @param bottom Bottom of the matrix
     * @param top Top of the matrix
     * @param near Near
     * @param far Far
     */
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

    /**
     * @brief Set the position where the matrix should look
     * 
     * @param rm 
     * @param eye eye
     * @param eye center
     * @param eye up
     */
    void setLookAt(float rm[], Vec3f eye, Vec3f center, Vec3f up) {
        // See the OpenGL GLUT documentation for gluLookAt for a description
        // of the algorithm. We implement it in a straightforward way:
        Vec3f f = center - eye;
        // Normalize f
        float rlf = 1.0f / length(f);
        f*=rlf;
        // compute s = f x up (x means "cross product")
        Vec3f s;
        s.x = f.y * up.z - f.z * up.y;
        s.y = f.z * up.x - f.x * up.z;
        s.z = f.x * up.y - f.y * up.x;
        // and normalize s
        float rls = 1.0f / length(s);
        s *= rls;
        // compute u = s x f
        Vec3f u;
        u.x = s.y * f.z - s.z * f.y;
        u.y = s.z * f.x - s.x * f.z;
        u.z = s.x * f.y - s.y * f.x;
        rm[0] = s.x;
        rm[1] = u.x;
        rm[2] = -f.x;
        rm[3] = 0.0f;
        rm[4] = s.y;
        rm[5] = u.y;
        rm[6] = -f.y;
        rm[7] = 0.0f;
        rm[8] = s.z;
        rm[9] = u.z;
        rm[10] = -f.z;
        rm[11] = 0.0f;
        rm[12] = 0.0f;
        rm[13] = 0.0f;
        rm[14] = 0.0f;
        rm[15] = 1.0f;
        translate(rm, -eye);
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