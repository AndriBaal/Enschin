#pragma once

#include "game_object.h"
#include "context.h"

class GameObject;
struct UpdateContext;
struct RenderContext;
struct Chunk {
private:
    std::vector<GameObject *> gameObjects;
    Vec2i matrixPosition;
public:
    Chunk() = default;
    Chunk(Vec2i matrixPosition, Vec2i chunkSize) : matrixPosition(matrixPosition){}
    Vec2i getMatrixPosition(){ return matrixPosition; }
    bool isInside(const GameObject& g, Vec2i chunkSize);
    void update(const UpdateContext& ctx);
    void render(const RenderContext& ctx);
    void add(GameObject *gameObject);
};