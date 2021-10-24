#include <iostream>


void copy(float result[])
{
    float origin[16] = {
        -0.707107,   0.707107,    0,       0,
        0,       	1,       	-0,      0,
        0,      	-0,      	-1,      0,
        -0.58,   	0.9975,  	-3,      1
    };
    for (int i = 0; i < 16; i++)
    {
        result[i] = origin[i];
    }
}

int main()
{
    float result[16] = {0};

    copy(result);

    for (int i = 0; i < 4; i++)
    {
        std::cout
        << result[i*4] << "\t"
        << result[i*4+1] << "\t"
        << result[i*4+2] << "\t"
        << result[i*4+3] << "\t"
        << std::endl;
    }
}