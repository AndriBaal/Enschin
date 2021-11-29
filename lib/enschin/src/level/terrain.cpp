#include <enschin/terrain.h>

Terrain::Terrain(float* vertices, unsigned int amountOfVertices, bool collisionOutside) {
    b2Vec2 groundVertices[amountOfVertices];
    amountOfElements = amountOfVertices / 2 - 1;
    elements = new TerrainElement[amountOfElements];

    for (int i = 0; i < amountOfVertices / 2; i++) {
        groundVertices[i].Set(vertices[i*4], vertices[i*4+1]);
    }

    int counter = 0;
    for (int i = amountOfVertices / 2.0f; i < amountOfVertices; i++) {
        groundVertices[i].Set(vertices[(amountOfVertices*2-1)-counter*4-1], vertices[(amountOfVertices*2-1)-counter*4]);
        counter++;
    }

    if (collisionOutside)
        std::reverse(groundVertices, groundVertices + sizeof(groundVertices)/sizeof(groundVertices[0]));

    for (int i = 0; i < amountOfElements; i++) {
        float modelVertices[16] {
            vertices[i * 4 + 2],
            vertices[i * 4 + 3],
            0,
            0,

            vertices[i * 4 + 6],
            vertices[i * 4 + 7],
            1,
            0,

            vertices[i * 4 + 4],
            vertices[i * 4 + 5],
            1,
            1,

            vertices[i * 4 + 0],
            vertices[i * 4 + 1],
            0,
            1
        };

        elements[i] = TerrainElement{
                new RenderModel(modelVertices),
                Color{1, 0, 0, 1}
        };
    }
    ground = new b2ChainShape();
    ground->CreateLoop(groundVertices, amountOfVertices);
}

void Terrain::free() const {
    for (int i = 0; i < amountOfElements; i++) {
        elements[i].free();
    }
    delete ground;
    delete elements;
}