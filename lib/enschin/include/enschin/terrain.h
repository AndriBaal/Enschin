#pragma once

#include <box2d/b2_chain_shape.h>
#include <box2d/b2_math.h>
#include "model.h"
#include "model.h"
#include "color.h"
#include "game_object.h"
#include "terrain_definition.h"
#include "enschin/chunk_manager.h"
#include <algorithm>
#include <iostream>


class Terrain {
private:
    std::vector<GameObject *> groundObjects;
public:
    Terrain(const UpdateContext &ctx, const TerrainDefinition *terrainDefinition, Vec2 pos);

    ~Terrain();

    std::vector<GameObject *> &getGroundObjects() { return groundObjects; }
};