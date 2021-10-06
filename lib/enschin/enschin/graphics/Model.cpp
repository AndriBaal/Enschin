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


Model::Model(float vertices[], unsigned short amountOfVertices, unsigned int indices[], unsigned short amountOfIndices)
{
    this->amountOfVertices = amountOfVertices;
    this->amountOfIndicies = amountOfIndices;
    VertexBuffer* vb = new VertexBuffer(vertices, 4 * amountOfVertices * sizeof(float));
    ib = new IndexBuffer(indices, amountOfIndices);

    VertexBufferLayout layout;
    layout.addFloat(2);
    layout.addFloat(2);

    va = new VertexArray();
    va->addBuffer(*vb, layout);

    
}