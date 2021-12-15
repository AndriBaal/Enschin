#pragma once

#include "chunk.h"
#include "context.h"

class Chunk;
class UpdateContext;
class RenderContext;
class GameObject;
class ChunkManager {
private:
    Chunk* chunks;
    Vec2i amountOfChunks;
    Vec2i chunksSize;
    float chunkUpdateRadius;
    unsigned short totalChunks;
public:
    ChunkManager() = default;
    void init(Vec2i amountOfChunks, Vec2i chunksSize, float chunkUpdateRadius = 5);
    void update(UpdateContext ctx) const;
    void render(RenderContext ctx) const;
    void addGameObject(GameObject* gameObject) const;
    Chunk* getChunk(Vec2f worldCoords) const;
    bool isInChunk(Vec2f* vertices) const;
};