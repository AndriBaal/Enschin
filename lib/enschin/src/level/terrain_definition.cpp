#include <enschin/terrain_definition.h>

TerrainDefinition::TerrainDefinition(float *vertices, unsigned int amountOfVertices) {
    amountOfModels = amountOfVertices / 2 - 1;
    groundModels = new Model*[amountOfModels];

    for (int i = 0; i < amountOfModels; i++) {
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
        groundModels[i] = new Model(modelVertices);
    }
}

TerrainDefinition::~TerrainDefinition() {
    for (int i = 0; i < amountOfModels; i++) {
        delete groundModels[i];
    }
    delete groundModels;
}