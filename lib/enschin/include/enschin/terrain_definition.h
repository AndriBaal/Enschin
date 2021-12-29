#pragma once

#include "model.h"

struct TerrainDefinition {
private:
    Model** groundModels;
    Vec2f* modelCenters;
    unsigned int amountOfModels;
public:
    TerrainDefinition(float* vertices, unsigned int amountOfVertices);
    ~TerrainDefinition();
    unsigned int getAmountOfModels() const { return amountOfModels; }
    Model** getModels() const { return groundModels; }
    Vec2f* getModelCenters() const { return modelCenters; }
};