#include <enschin/terrain.h>

Terrain::Terrain(const ChunkManager& chunkManager, const TerrainDefinition* terrainDefinition, Vec2 pos){
    Model** m = terrainDefinition->getModels();
    for (int i = 0; i < terrainDefinition->getAmountOfModels(); i++) {
        
    }
}

Terrain::~Terrain() {

}