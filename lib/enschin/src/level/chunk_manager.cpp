#include <enschin/chunk_manager.h>

void ChunkManager::getChunk(Vec2 coords) const {

}

bool ChunkManager::isInChunk(const b2Shape* collisionShape, const b2Body* body) const {
//    bool inScreen() const {
//        b2PolygonShape windowShape;
//        windowShape.SetAsBox(camera.getFov() * camera.getRatio(), camera.getFov());
//        Vec2 camPos = camera.getCameraPosition();
//        b2Transform cameraTransform = {{camPos.x, camPos.y}, b2Rot(0)};
//        return b2TestOverlap(collisionShape, 0, &windowShape, 0, body->GetTransform(), cameraTransform);
//    }
}
