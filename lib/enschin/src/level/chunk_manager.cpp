#include <enschin/chunk_manager.h>


ChunkManager::ChunkManager(Vec2i amountOfChunks, Vec2i chunksSize, Vec2i updates)
    : amountOfChunks(amountOfChunks), chunksSize(chunksSize),
      updates(updates), totalChunks(amountOfChunks.x * amountOfChunks.y) {
    chunks = new Chunk[totalChunks];
    outsideChunk = new Chunk();
    for (int i = 0; i < totalChunks; i++) {
        Vec2i indexPosition = {
                i % amountOfChunks.x,
                i / amountOfChunks.x
        };

        Vec2i matrixPosition = {
                indexPosition.x - amountOfChunks.x / 2,
                indexPosition.y - amountOfChunks.y / 2,
        };
//        if (amountOfChunks.x % 2 == 1) matrixPosition.x++;
        std::cout << matrixPosition << std::endl;
        chunks[i] = Chunk(matrixPosition, chunksSize);
    }
}

ChunkManager::~ChunkManager() {
    for (int i = 0; i < totalChunks; i++)
        delete &chunks[i];
    delete chunks;
}


Chunk* ChunkManager::getChunk(Vec2f coords) const {
    int x = coords.x / chunksSize.x + amountOfChunks.x / 2;
    int y = coords.y / chunksSize.y + amountOfChunks.y / 2;
    int index = y * amountOfChunks.x + x;
//    if (index >= totalChunks || index < 0) {
//        std::cout << "kjldshfkljsdhflkjsdhf" << std::endl;
//        return outsideChunk;
//    }
    return &chunks[index];
}

Chunk* ChunkManager::getChunk(Vec2i matrixPosition) const {
    return &chunks[totalChunks / 2 + matrixPosition.y * amountOfChunks.x + matrixPosition.x];
}


bool ChunkManager::isInChunk(Vec2f* vertices) const {
//    bool inScreen() const {
//        b2PolygonShape windowShape;
//        windowShape.SetAsBox(camera.getFov() * camera.getRatio(), camera.getFov());
//        Vec2 camPos = camera.getCameraPosition();
//        b2Transform cameraTransform = {{camPos.x, camPos.y}, b2Rot(0)};
//        return b2TestOverlap(collisionShape, 0, &windowShape, 0, body->GetTransform(), cameraTransform);
//    }
    return true;
}

void ChunkManager::addGameObject(GameObject* gameObject) const {
    Chunk* chunk = getChunk(gameObject->getPos());
    std::cout << gameObject->getName() << chunk->getMatrixPosition() << std::endl;
    chunk->add(gameObject);
    gameObject->setCurrentChunk(chunk);
}

void ChunkManager::update(const UpdateContext& ctx) const {
    Chunk* mainChunk = getMainChunk(ctx.camera);
    if (mainChunk != outsideChunk) {
        for (int y = -updates.y; y <= updates.y; y++) {
            for (int x = -updates.x; x <= updates.x; x++) {
                getChunk(mainChunk->getMatrixPosition() + Vec2i{x, y})->update(ctx);
            }
        }
    }
}

void ChunkManager::render(const RenderContext& ctx) const {
    short renders = 2;
    Chunk* mainChunk = getMainChunk(ctx.camera);
    if (mainChunk != outsideChunk) {
        for (int y = -updates.y; y <= updates.y; y++) {
            for (int x = -updates.x; x <= updates.x; x++) {
                getChunk(mainChunk->getMatrixPosition() + Vec2i{x, y})->render(ctx);
            }
        }
    }
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