#include <enschin/chunk_manager.h>

Vec2 ChunkManager::getIndices(Vec2 coords) const {
    return {
        coords.x / chunkDimension.x,
        coords.y / chunkDimension.y
    };
}

void ChunkManager::init(Vec2 amountOfChunks, Vec2 chunkDimension, float chunkUpdateRadius) {
    this->amountOfChunks = amountOfChunks;
    this->chunkDimension = chunkDimension;
    this-> chunkUpdateRadius = chunkUpdateRadius;
    delete []chunks;
    delete chunks;
    chunks = new Chunk[int(amountOfChunks.x * amountOfChunks.y)];
    for (int x = -amountOfChunks.x / 2.0; x < amountOfChunks.x/2.0; x++) {
        for (int y = amountOfChunks.y / 2.0; y > -amountOfChunks.y / 2.0; y+=chunkDimension.y) {
            chunks[x + y];
        }
    }
}

Chunk* ChunkManager::get(Vec2 gridPos) const {
    return &chunks[];
}

Chunk* ChunkManager::getChunk(Vec2 coords) const {
    if (coords.x < amountOfChunks.x/2.0 &&
        coords.y < amountOfChunks.y/2.0 &&
        coords.x > -amountOfChunks.y/2.0 &&
        coords.x > -amountOfChunks.y/2.0) {
        return get(getIndices(coords));
    }
    return nullptr;
}

bool ChunkManager::isInChunk(Vec2* vertices) const {
//    bool inScreen() const {
//        b2PolygonShape windowShape;
//        windowShape.SetAsBox(camera.getFov() * camera.getRatio(), camera.getFov());
//        Vec2 camPos = camera.getCameraPosition();
//        b2Transform cameraTransform = {{camPos.x, camPos.y}, b2Rot(0)};
//        return b2TestOverlap(collisionShape, 0, &windowShape, 0, body->GetTransform(), cameraTransform);
//    }
}

void ChunkManager::addGameObject(GameObject *gameObject) {
    getChunk(gameObject->getPos())->add(gameObject);
}

void ChunkManager::update(UpdateContext ctx) {
    for (int x = 0; x < amountOfChunks.x; x++)
        for (int y = 0; y < amountOfChunks.x; y++)
            chunks[y][x].update(ctx);
}

void ChunkManager::render(RenderContext ctx) {
    unsigned short horizontalRenders = ctx.camera.getRatio() / chunkDimension.x;
    unsigned short verticalRenders = ctx.camera.getFov() / chunkDimension.y;
    Vec2 mainChunk = getChunk(ctx.camera.getCameraPosition())->getPosition();
    for (int i = 1; i < horizontalRenders / 2; i++ ) {
        for (int j = 0; j < verticalRenders / 2; j++) {
            get({
                mainChunk.x + i,
                mainChunk.y + j
            })->render(ctx);
            get({
                mainChunk.x - i,
                mainChunk.y - j
            })->render(ctx);
        }
    }
    get(mainChunk)->render(ctx);
}