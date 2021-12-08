#include <enschin/terrain.h>

Terrain::Terrain(const UpdateContext& ctx, const TerrainDefinition* terrainDefinition, Vec2 pos){
    Model** m = terrainDefinition->getModels();
    for (int i = 0; i < terrainDefinition->getAmountOfModels(); i++) {
        Color c = Color{0, 0, 1, 1};
        groundObjects.push_back(new GameObject(ctx, "terrain", m[i], &c, pos));
    }
}

Terrain::~Terrain() {
    for (auto& object : groundObjects)
        object->kill();
}