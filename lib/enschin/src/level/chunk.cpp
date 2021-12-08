#include <enschin/chunk.h>

void Chunk::add(GameObject* gameObject) {
    gameObjects.push_back(gameObject);
}