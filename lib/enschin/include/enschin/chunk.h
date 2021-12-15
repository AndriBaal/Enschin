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
    Vec2i getMatrixPosition(){ return matrixPosition; }
    void setMatrixPosition(Vec2i matrixPosition){ this->matrixPosition = matrixPosition; }
    void update(const UpdateContext& ctx);
    void render(const RenderContext& ctx);
    void add(GameObject *gameObject);
};