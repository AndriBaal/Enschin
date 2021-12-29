#include <enschin/chunk_manager.h>


ChunkManager::ChunkManager(int left, int right, int bottom, int top, Vec2i chunkSize, Vec2i updates)
    : left(left), right(right), bottom(bottom), top(top),
    chunksSize(chunksSize), updates(updates),
    amountOfChunks({1 + left + right, 1 + bottom + top}), totalChunks(amountOfChunks.x * amountOfChunks.y) {
    chunks = new Chunk[totalChunks];
    outside = new Chunk();

    for (int y = 0; y < amountOfChunks.x; y++) {
        for (int x = 0; x < amountOfChunks.y; x++) {
            Vec2i matrixPosition = {
                x - left,
                y - bottom
            };
            chunks[y * amountOfChunks.x + x] = Chunk(matrixPosition, chunksSize);
        }
    }
}

ChunkManager::~ChunkManager() {
    for (int i = 0; i < totalChunks; i++) {
        delete &chunks[i];
    }
    delete chunks;
}


Chunk* ChunkManager::getChunk(Vec2f coords) const {
////    if (index >= totalChunks || index < 0) {
////        std::cout << "kjldshfkljsdhflkjsdhf" << std::endl;
////        return outsideChunk;
////    }
    Vec2i matrixPosition =  {
        (int) ((coords.x - chunksSize.x) / chunksSize.x + amountOfChunks.x / 2.0),
        (int) ((coords.y - chunksSize.y) / chunksSize.y + amountOfChunks.y / 2.0)
    };
    int index = matrixPosition.y * amountOfChunks.x + matrixPosition.x;
    std::cout << index << std::endl;

    return &chunks[index];
}

Chunk* ChunkManager::getChunk(Vec2i matrixPosition) const {
    return &chunks[totalChunks / 2 + matrixPosition.y * amountOfChunks.x + matrixPosition.x];
}


void ChunkManager::addGameObject(GameObject* gameObject) const {
    Chunk* chunk = getChunk(gameObject->getPos());
    chunk->add(gameObject);
    gameObject->setCurrentChunk(chunk);
}

void ChunkManager::update(const UpdateContext& ctx) const {
    Chunk* mainChunk = getMainChunk(ctx.camera);
    mainChunk->update(ctx);
//    if (mainChunk != outside) {
//        for (int y = -updates.y; y <= updates.y; y++) {
//            for (int x = -updates.x; x <= updates.x; x++) {
//                getChunk(mainChunk->getMatrixPosition() + Vec2i{x, y})->update(ctx);
//            }
//        }
//    }
}

void ChunkManager::render(const RenderContext& ctx) const {
    short renders = 2;
    Chunk* mainChunk = getMainChunk(ctx.camera);
    mainChunk->render(ctx);
//    if (mainChunk != outside) {
//        for (int y = -updates.y; y <= updates.y; y++) {
//            for (int x = -updates.x; x <= updates.x; x++) {
//                getChunk(mainChunk->getMatrixPosition() + Vec2i{x, y})->render(ctx);
//            }
//        }
//    }
}

Chunk* ChunkManager::getMainChunk(const Camera& cam) const {
    Chunk* mainChunk = nullptr;
    if (cam.getCameraMode() == BODY) {
        GameObject* go = (GameObject *) (cam.getCameraTarget().GetUserData().pointer);
        mainChunk = go->getCurrentChunk();
    } else {
        mainChunk = getChunk(cam.getCameraPosition());
    }
    return mainChunk;
}