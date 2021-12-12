#pragma once

#include "game_object.h"
#include "context.h"

class GameObject;
struct UpdateContext;
struct RenderContext;
struct Chunk {
private:
    std::vector<GameObject *> gameObjects;
    Vec2 matrixPosition;
public:
    Chunk() = default;
    Vec2 getMatrixPosition(){ return matrixPosition; }
    void setMatrixPosition(Vec2 matrixPosition){ this->matrixPosition = matrixPosition; }
    void update(const UpdateContext& ctx);
    void render(const RenderContext& ctx);
    void add(GameObject *gameObject);
};