#include <enschin/terrain_definition.h>

TerrainDefinition::TerrainDefinition(float* vertices, unsigned int amountOfVertices) {
    amountOfModels = amountOfVertices / 2 - 1;
    groundModels = new Model*[amountOfModels];
    modelCenters = new Vec2f[amountOfModels];

    for (int i = 0; i < amountOfModels; i++) {
        Vec2f v[4] = {
        {vertices[i * 4 + 2], vertices[i * 4 + 3]},
        {vertices[i * 4 + 6], vertices[i * 4 + 7]},
        {vertices[i * 4 + 4], vertices[i * 4 + 5]},
        {vertices[i * 4 + 0], vertices[i * 4 + 1]},
        };
        Vec2f center = (v[0] + v[1] + v[2] + v[3]) / 4.0f;
        for (auto & ve : v)
            ve -= center;
        modelCenters[i] = center;

        float modelVertices[16] {
        v[0].x,v[0].y,0,0,
        v[1].x, v[1].y, 1, 0,
        v[2].x, v[2].y, 1, 1,
        v[3].x, v[3].y, 0, 1
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