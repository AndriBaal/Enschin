#include <enschin/chunk.h>

void Chunk::add(GameObject* gameObject) {
    gameObjects.push_back(gameObject);
}

void Chunk::update(const UpdateContext &ctx) {
    for (auto& g : gameObjects)
        g->update(ctx);
}

void Chunk::render(const RenderContext &ctx) {
    for (auto& g : gameObjects)
        g->render(ctx);
}