#pragma once

#include "chunk.h"

class ChunkManager {
private:
    Chunk* chunks;
    Vec2 amountOfChunks;
public:
    Chunk& getChunk(Vec2 coords) const;
    bool isInChunk(Vec2* vertices) const;
};