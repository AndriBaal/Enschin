#pragma once
#include "game_object.h"

#define CHUNK_WIDTH 10
#define CHUNK_HEIGHT 10


struct Chunk {
    std::vector<GameObject*> gameObjects;

};