#include "Model.h"

const unsigned int Model::INDICES[] = {
        0, 1, 2,
        2, 3, 0
};


Model::Model(float vertices[], int amountOfVertices)
{
    this->amountOfVertices = amountOfVertices;
    VertexBuffer* vb = new VertexBuffer(vertices, 4 * 4 * sizeof(float));
    ib = new IndexBuffer(INDICES, 6);

    VertexBufferLayout layout;
    layout.addFloat(2);
    layout.addFloat(2);

    va = new VertexArray();
    va->addBuffer(*vb, layout);

    
}