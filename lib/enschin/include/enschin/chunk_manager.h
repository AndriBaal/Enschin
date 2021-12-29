#pragma once

#include "chunk.h"
#include "context.h"
#include <math.h>

class Chunk;
class UpdateContext;
class RenderContext;
class GameObject;
class ChunkManager {
private:
    Chunk* chunks;
    Chunk* outsideChunk;
    Vec2i updates;
    const Vec2i amountOfChunks;
    const Vec2i chunksSize;
    unsigned int totalChunks;
public:
    ChunkManager(Vec2i amountOfChunks, Vec2i chunksSize, Vec2i updates = {4, 0});
    ~ChunkManager();
    void update(const UpdateContext& ctx) const;
    void render(const RenderContext& ctx) const;
    void addGameObject(GameObject* gameObject) const;

    Chunk* getMainChunk(const Camera& cam) const;
    Chunk* getChunk(Vec2f worldCoords) const;
    Chunk* getChunk(Vec2i matrixPosition) const;

    Vec2i getChunkSize() const { return chunksSize; }
    Vec2i getAmountOfChunks() const { return amountOfChunks; }
    float getTotalChunks() const { return totalChunks; }

    bool isInChunk(Vec2f* vertices) const;
};