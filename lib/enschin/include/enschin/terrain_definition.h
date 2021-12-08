#pragma once

struct TerrainDefinition {
private:
    Model** groundModels;
    unsigned int amountOfModels;
public:
    TerrainDefinition(float* vertices, unsigned int amountOfVertices);
    ~TerrainDefinition();
    unsigned int getAmountOfModels() const { return amountOfModels; }
    Model** getModels() const { return groundModels; }
};