#include <enschin/chunk_manager.h>


void ChunkManager::init(Vec2 amountOfChunks, Vec2 chunkDimension, float chunkUpdateRadius) {
    this->amountOfChunks = amountOfChunks;
    this->chunkDimension = chunkDimension;
    this-> chunkUpdateRadius = chunkUpdateRadius;
    totalChunks =  int(amountOfChunks.x * amountOfChunks.y);
    chunks = new Chunk[int(amountOfChunks.x * amountOfChunks.y)];
    for (int i = 0; i < totalChunks; i++) {
        Vec2 indexPosition = {
                float(i % int(amountOfChunks.x)),
                floor(i / amountOfChunks.x)
        };
        chunks[i].setMatrixPosition({
            floor((indexPosition.x + 1) - amountOfChunks.x / 2),
            (indexPosition.y - 1) - floor(amountOfChunks.y / 2)
        });
    }
}


Chunk* ChunkManager::getChunk(Vec2 coords) const {
    return &chunks[int(coords.x / chunkDimension.x) * int(coords.y / chunkDimension.y)];
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
    Vec2 mainChunk = getChunk(ctx.camera.getCameraPosition())->getMatrixPosition();
    for (int i = 0; i < totalChunks; i++) {
        chunks[i].render(ctx);
    }
//    for (int i = 1; i < horizontalRenders / 2; i++ ) {
//        for (int j = 0; j < verticalRenders / 2; j++) {
//            get({
//                mainChunk.x + i,
//                mainChunk.y + j
//            })->render(ctx);
//            get({
//                mainChunk.x - i,
//                mainChunk.y - j
//            })->render(ctx);
//        }
//    }
//    get(mainChunk)->render(ctx);

}