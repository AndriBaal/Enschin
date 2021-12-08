#pragma once
#include <box2d/b2_chain_shape.h>
#include <box2d/b2_math.h>
#include "model.h"
#include "model.h"
#include "color.h"
#include "game_object.h"
#include "terrain_definition.h"
#include <algorithm>
#include <iostream>


class Terrain{
private:
    std::vector<GameObject*> groundObjects;
    std::vector<GameObject*> backgroundObjects;
    /////////////////
    //Delete objects via .kill();
    ///////////////
public:
    Terrain(const ChunkManager& chunkManager, const TerrainDefinition* terrainDefinition, Vec2 pos);
    ~Terrain();
    std::vector<GameObject*>& getGroundObjects(){ return groundObjects; }
    std::vector<GameObject*>& getBackgroundObjects() { return backgroundObjects; }
};