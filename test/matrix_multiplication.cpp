#include <iostream>

void multiply(float result[], float lhs[], float rhs[])
{
    for (int i = 0; i < 15; i+= 4)
    {
        for(int j = 0; j < 4; j++)
        {
            result[i+j] = lhs[i] * rhs[j] +
                        lhs[i+1] * rhs[4+j] +
                        lhs[i+2] * rhs[8+j] +
                        lhs[i+3] * rhs[12+j];
        }
    }
}

int main()
{
    float mat1[16] = {
    5, 7, 9, 10,
    2, 3, 2, 8,
    8, 11, 2, 3,
    3,3, 4, 8,
    };

    float mat2[16] = {
        3, 10, 12, 18,
        12, 1, 4, 9,
        9, 10, 12, 2,
        3, 12, 4, 10,
    };

    float result[16] = {0};

    multiply(result, mat1, mat2);

    std::cout << "Result: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << result[i*4] << "\t"
                << result[i*4+1] << "\t"
                << result[i*4+2] << "\t"
                << result[i*4+3] << "\t"
                << std::endl;
    }
    
}