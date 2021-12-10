#pragma once

#include "game_object.h"
#include "context.h"

class GameObject;
struct UpdateContext;
struct RenderContext;
struct Chunk {
private:
    std::vector<GameObject *> gameObjects;
    Vec2 position;
public:
    Chunk() = default;
    Chunk(Vec2 position);
    Vec2 getPosition() const { return position; }
    void update(const UpdateContext& ctx);
    void render(const RenderContext& ctx);
    void add(GameObject *gameObject);
};