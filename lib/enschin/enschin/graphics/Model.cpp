#include "Model.h"
#include <iostream>

// 0, 1, 2,
// 2, 3, 0 Indicies for 4 corners

// 1, 2, 3,
// 0, 4, 5,
// 0, 1, 3,
// 0, 4, 3 Hexagon

// 2, 3, 4,
// 2, 4, 0,
// 0, 1, 2, Pentagon

const float Model::texCoords[8] = {
    0.0f, 0.0f, //Bottom left
    1.0f, 0.0f, //Bottom right
    1.0f, 1.0f, //Top right
    0.0f, 1.0f //Top left
};


Model::Model(float vertices[], unsigned short amountOfVertices, unsigned int indices[], unsigned short amountOfIndices)
    : amountOfIndices(amountOfIndices), amountOfVertices(amountOfVertices)
{
    float verticesTexCoord[amountOfVertices*4];
    for (int i = 0; i < amountOfVertices*4; i+=4)
    {
        verticesTexCoord[i] = vertices[i/2];
        verticesTexCoord[i+1] = vertices[i/2+1];
        if (i/2+1 < 8)
        {
            verticesTexCoord[i+2] = texCoords[i/2];
            verticesTexCoord[i+3] = texCoords[i/2+1];
        }
        else
        {
            verticesTexCoord[i+2] = texCoords[0];
            verticesTexCoord[i+3] = texCoords[0];
        }
    }
    VertexBuffer* vb = new VertexBuffer(verticesTexCoord, 4 * amountOfVertices * sizeof(float));
    ib = new IndexBuffer(indices, amountOfIndices);

    VertexBufferLayout layout;
    layout.addFloat(2);
    layout.addFloat(2);

    va = new VertexArray();
    va->addBuffer(*vb, layout);

    
}