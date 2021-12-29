#include <enschin/terrain.h>

Terrain::Terrain(const UpdateContext& ctx, const TerrainDefinition* terrainDefinition, Vec2f pos){
    Model** m = terrainDefinition->getModels();
    Vec2f* mc = terrainDefinition->getModelCenters();
    for (int i = 0; i < terrainDefinition->getAmountOfModels(); i++) {
        groundObjects.push_back(new GameObject(ctx, "terrain", m[i], ctx.commonRes.getColor("yellow"), pos + mc[i], true, true, true));
    }
}

Terrain::~Terrain() {
    for (auto& object : groundObjects)
        object->kill();
}