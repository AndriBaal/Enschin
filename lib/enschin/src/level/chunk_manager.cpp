#include <enschin/chunk_manager.h>


void ChunkManager::init(Vec2i amountOfChunks, Vec2i chunksSize, float chunkUpdateRadius) {
    this->amountOfChunks = amountOfChunks;
    this->chunksSize = chunksSize;
    this-> chunkUpdateRadius = chunkUpdateRadius;
    totalChunks =  amountOfChunks.x * amountOfChunks.y;
    chunks = new Chunk[totalChunks];
    for (int i = 0; i < totalChunks; i++) {
        Vec2i indexPosition = {
                i % amountOfChunks.x,
                i / amountOfChunks.y
        };
        Vec2i matrixPosition = {
            indexPosition.x - amountOfChunks.x / 2,
            indexPosition.y - amountOfChunks.y / 2,
        };
        if (amountOfChunks.x % 2 == 1) matrixPosition.x++;
        chunks[i].setMatrixPosition(matrixPosition);
    }
}


Chunk* ChunkManager::getChunk(Vec2f coords) const {
    int x = coords.x / chunksSize.x + amountOfChunks.x / 2;
    int y = coords.y / chunksSize.y + amountOfChunks.y / 2;
    Chunk* chunk = &chunks[y * amountOfChunks.x + x];
    std::cout << "Input: " << coords << "  Output: " << chunk->getMatrixPosition() << std::endl;
    return chunk;
}


bool ChunkManager::isInChunk(Vec2f* vertices) const {
//    bool inScreen() const {
//        b2PolygonShape windowShape;
//        windowShape.SetAsBox(camera.getFov() * camera.getRatio(), camera.getFov());
//        Vec2 camPos = camera.getCameraPosition();
//        b2Transform cameraTransform = {{camPos.x, camPos.y}, b2Rot(0)};
//        return b2TestOverlap(collisionShape, 0, &windowShape, 0, body->GetTransform(), cameraTransform);
//    }
    return false;
}

void ChunkManager::addGameObject(GameObject *gameObject) const {
    getChunk(gameObject->getPos())->add(gameObject);
}

void ChunkManager::update(UpdateContext ctx) const {
    for (int i = 0; i < totalChunks; i++) {
        chunks[i].update(ctx);
    }
}

void ChunkManager::render(RenderContext ctx) const {
    unsigned short horizontalRenders = ctx.camera.getRatio() / chunksSize.x;
    unsigned short verticalRenders = ctx.camera.getFov() / chunksSize.y;
    Chunk* mainChunk = getChunk(ctx.camera.getCameraPosition());
    mainChunk->render(ctx);
}