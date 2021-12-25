#include <enschin/chunk.h>

bool Chunk::isInside(const GameObject &g, Vec2i chunkSize) {
    Vec2i worldPosition = matrixPosition * chunkSize;
    return (
        g.getBody()->GetPosition().x > worldPosition.x &&
        g.getBody()->GetPosition().x < worldPosition.x + chunkSize.x &&
        g.getBody()->GetPosition().y > worldPosition.y &&
        g.getBody()->GetPosition().y > worldPosition.x + chunkSize.y
    );
}

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
