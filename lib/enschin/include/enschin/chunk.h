#pragma once
#include "game_object.h"

#define CHUNK_WIDTH 10
#define CHUNK_HEIGHT 10


struct Chunk {
    Vec2 position;
    std::vector<GameObject*> gameObjects;
};