#include <enschin/chunk.h>

bool Chunk::isInside(const GameObject &g, Vec2i chunkSize) {
    Vec2f worldPosition;
    worldPosition.x = matrixPosition.x * chunkSize.x - chunkSize.x/2.0;
    worldPosition.y = matrixPosition.y * chunkSize.y - chunkSize.y/2.0;
    std::cout << matrixPosition << worldPosition << std::endl;
    return (
        g.getPos().x >= worldPosition.x &&
        g.getPos().x < worldPosition.x + chunkSize.x &&
        g.getPos().y >= worldPosition.y &&
        g.getPos().y < worldPosition.y + chunkSize.y
    );
}

Chunk::~Chunk() {
    for (auto g : gameObjects)
        delete g;
}

void Chunk::add(GameObject* gameObject) {
    gameObjects.push_back(gameObject);
}

void Chunk::update(const UpdateContext &ctx) {
    auto it = gameObjects.begin();
    while(it != gameObjects.end()) {
        (*it)->update(ctx);
        if (!(*it)->isAlive()) {
            it = gameObjects.erase(it);
            delete *it;
        } else if (!isInside(*(*it), ctx.level.getChunkManager().getChunkSize())) {
            ctx.level.addGameObject(*it);
            it = gameObjects.erase(it);
        } else {
            ++it;
        }
    }

}

void Chunk::render(const RenderContext &ctx) {
    for (auto g : gameObjects)
        g->render(ctx);
}
