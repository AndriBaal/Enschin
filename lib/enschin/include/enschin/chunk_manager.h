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
    unsigned int verticalChunks;
    unsigned int horizontalChunks;
    unsigned int chunkWidth;
    unsigned int chunkHeight;
    float chunkUpdateRadius;
    unsigned short totalChunks;
public:
    ChunkManager() = default;
    void init(unsigned int verticalChunks, unsigned int  horizontalChunks, unsigned int chunkWidth, unsigned int chunkHeight, float chunkUpdateRadius = 5);
    void update(UpdateContext ctx) const;
    void render(RenderContext ctx) const;
    void addGameObject(GameObject* gameObject) const;
    Chunk* getChunk(Vec2f worldCoords) const;
    bool isInChunk(Vec2f* vertices) const;
};