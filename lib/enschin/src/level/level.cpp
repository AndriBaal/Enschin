#include <enschin/level.h>

Level::Level(Vec2i amountOfChunks, Vec2i chunkSizes, Vec2f gravity) {
    world.SetGravity({gravity.x, gravity.y});
    world.SetContactListener(this->contactListener);

    chunkManager = new ChunkManager(amountOfChunks, chunkSizes);
}

Level::~Level() {

}

void Level::addGameObject(GameObject *gameObject) const {
    chunkManager->addGameObject(gameObject);
}

void Level::addTerrain(const UpdateContext& ctx, const TerrainDefinition* terrainDef, const Color* color, Vec2f positionOffSet) {
    Terrain* terrain = new Terrain(ctx, terrainDef, positionOffSet);
    terrains.push_back(terrain);
}

void Level::removeTerrain(unsigned int id) {
    //world.DestroyBody(terrains.at(id)->body);
}

void ContactListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold) {
    GameObject *gA = (GameObject *) contact->GetFixtureA()->GetBody()->GetUserData().pointer;
    GameObject *gB = (GameObject *) contact->GetFixtureB()->GetBody()->GetUserData().pointer;

    if (gA != 0 && gB != 0) {
        gA->onCollision(gB);
        gB->onCollision(gA);
    } else if (gA == 0) {
        gB->onCollision();
    } else if (gB == 0) {
        gA->onCollision();
    }
}

void ContactListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse) {
    GameObject *gA = (GameObject *) contact->GetFixtureA()->GetBody()->GetUserData().pointer;
    GameObject *gB = (GameObject *) contact->GetFixtureB()->GetBody()->GetUserData().pointer;

    if (gA != 0 && gB != 0) {
        gA->onRelease(gB);
        gB->onRelease(gA);
    } else if (gA == 0) {
        gB->onRelease();
    } else {
        gA->onRelease();
    }
}