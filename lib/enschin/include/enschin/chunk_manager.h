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
    Chunk* outside;
    Vec2i updates;
    const Vec2i chunksSize;
    const int left;
    const int right;
    const int top;
    const int bottom;
    const Vec2i amountOfChunks;
    unsigned int totalChunks;
public:
    ChunkManager(int left, int right, int bottom, int top, Vec2i chunkSize, Vec2i updates = {1, 1});
    ~ChunkManager();
    void update(const UpdateContext& ctx) const;
    void render(const RenderContext& ctx) const;
    void addGameObject(GameObject* gameObject) const;

    Chunk* getMainChunk(const Camera& cam) const;
    Chunk* getChunk(Vec2f worldCoords) const;
    Chunk* getChunk(Vec2i matrixPosition) const;

    Vec2i getChunkSize() const { return chunksSize; }
    float getTotalChunks() const { return totalChunks; }
};