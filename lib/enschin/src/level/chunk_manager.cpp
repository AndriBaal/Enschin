#include <enschin/chunk_manager.h>


void ChunkManager::init(Vec2 amountOfChunks, Vec2 chunkDimension, float chunkUpdateRadius) {
    this->amountOfChunks = amountOfChunks;
    this->chunkDimension = chunkDimension;
    this-> chunkUpdateRadius = chunkUpdateRadius;
    totalChunks =  int(amountOfChunks.x * amountOfChunks.y);
    chunks = new Chunk[totalChunks];
    for (int i = 0; i < totalChunks; i++) {
        Vec2 indexPosition = {
                float(i % int(amountOfChunks.x)),
                floor(i / amountOfChunks.x)
        };
        Vec2 matrixPosition = {
            floor((indexPosition.x) - amountOfChunks.x / 2),
            (indexPosition.y) - floor(amountOfChunks.y / 2),
        };
        if (int(amountOfChunks.x) % 2 == 1) matrixPosition.x++;
        chunks[i].setMatrixPosition(matrixPosition);
    }
}


Chunk* ChunkManager::getChunk(Vec2 coords) const {
    int x = coords.x / chunkDimension.x + amountOfChunks.x / 2;
    int y = coords.y / chunkDimension.y + amountOfChunks.y / 2;
    std::cout << coords << "        " << Vec2{float(x), float(y)} <<"             "<< int(y * amountOfChunks.x + x) << std::endl;
    Chunk* chunk = &chunks[int(y * amountOfChunks.x + x)];
    std::cout << "Input: " << coords << "  Output: " << chunk->getMatrixPosition() << std::endl;
    return chunk;
}


bool ChunkManager::isInChunk(Vec2* vertices) const {
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
    unsigned short horizontalRenders = ctx.camera.getRatio() / chunkDimension.x;
    unsigned short verticalRenders = ctx.camera.getFov() / chunkDimension.y;
    Chunk* mainChunk = getChunk(ctx.camera.getCameraPosition());
    mainChunk->render(ctx);
}