#pragma once

#include "chunk.h"
#include "game_object.h"
#include "context.h"

class ChunkManager {
private:
    Chunk** chunks;
    Vec2 amountOfChunks;
    Vec2 chunkDimension;
    float chunkUpdateRadius;
public:
    ChunkManager() = default;
    void init(Vec2 amountOfChunks, Vec2 chunkDimension, float chunkUpdateRadius = 5);
    void update(UpdateContext ctx);
    void render(RenderContext ctx);
    void addGameObject(GameObject* gameObject);
    Chunk& getChunk(Vec2 worldCoords) const;
    Chunk& get(Vec2 gridPos) const;
    bool isInChunk(Vec2* vertices) const;
    Vec2 getAmounntOfChunks() const { return amountOfChunks; }
    Vec2 getChunkDimension() const { return chunkDimension; }
    Vec2 getIndices(Vec2 coords);
};