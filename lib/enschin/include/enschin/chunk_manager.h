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
    Vec2 amountOfChunks;
    Vec2 chunkDimension;
    float chunkUpdateRadius;
    unsigned short totalChunks;
public:
    ChunkManager() = default;
    void init(Vec2 amountOfChunks, Vec2 chunkDimension, float chunkUpdateRadius = 5);
    void update(UpdateContext ctx) const;
    void render(RenderContext ctx) const;
    void addGameObject(GameObject* gameObject) const;
    Chunk* getChunk(Vec2 worldCoords) const;
    bool isInChunk(Vec2* vertices) const;
    Vec2 getAmounntOfChunks() const { return amountOfChunks; }
    Vec2 getChunkDimension() const { return chunkDimension; }
};