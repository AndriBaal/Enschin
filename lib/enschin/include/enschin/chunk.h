#pragma once

#include "game_object.h"
#include "context.h"


struct Chunk {
private:
    std::vector<GameObject *> gameObjects;
public:
    Vec2 getPosition() const { return position; }
    void update(const UpdateContext& ctx);
    void render(const RenderContext& ctx);
    void add(GameObject *gameObject);
};