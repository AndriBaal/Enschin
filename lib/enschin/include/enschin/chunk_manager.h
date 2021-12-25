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
    const Vec2i amountOfChunks;
    const Vec2i chunksSize;
    float chunkUpdateRadius;
    unsigned int totalChunks;
public:
    ChunkManager(Vec2i amountOfChunks, Vec2i chunksSize, float chunkUpdateRadius = 5);
    void update(const UpdateContext& ctx) const;
    void render(const RenderContext& ctx) const;
    void addGameObject(GameObject* gameObject) const;

    Vec2i getChunkSize() const { return chunksSize; }
    Vec2i getAmountOfChunks() const { return amountOfChunks; }
    float getTotalChunks() const { return totalChunks; }

    Chunk* getChunk(Vec2f worldCoords) const;
    bool isInChunk(Vec2f* vertices) const;
};