#include <enschin/chunk.h>

bool Chunk::isInside(const GameObject &g, Vec2i chunkSize) {
    Vec2i worldPosition = matrixPosition * chunkSize;
    return (
        g.getPos().x >= worldPosition.x &&
        g.getPos().x < worldPosition.x + chunkSize.x &&
        g.getPos().y >= worldPosition.y &&
        g.getPos().y < worldPosition.y + chunkSize.y
    );
}

void Chunk::add(GameObject* gameObject) {
    gameObjects.push_back(gameObject);
}

void Chunk::update(const UpdateContext &ctx) {
    auto it = gameObjects.begin();
    while(it != gameObjects.end()) {
        (*it)->update(ctx);
        if (!isInside(*(*it), ctx.level.getChunkManager().getChunkSize())) {
            Chunk* newChunk = ctx.level.getChunkManager().getChunk((*it)->getPos());
            (*it)->setCurrentChunk(newChunk);
            newChunk->add((*it));
            it = gameObjects.erase(it);
            std::cout << "sdjkhksdfhsldkfksdfdhh" << std::endl;
        } else {
            ++it;
        }
    }

}

void Chunk::render(const RenderContext &ctx) {
    for (auto& g : gameObjects)
        g->render(ctx);
}
