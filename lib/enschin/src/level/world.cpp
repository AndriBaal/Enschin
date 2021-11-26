#include <enschin/world.h>

World::World(WorldBody& worldBody, Vec2 worldPos, Vec2 gravity) : worldBody(&worldBody) {

    world.SetGravity(gravity.toB2());
    world.SetContactListener(this->contactListener);
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(worldPos.x, worldPos.y);
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    groundBody->CreateFixture(worldBody.getChainShape(), 0.0f);
}

void World::update(const UContext& ctx) {
    world.Step(ctx.deltaTime, 6, 2);
}

void World::renderBackground(const RContext& ctx) {

}

void World::renderForeground(const RContext& ctx) {
    worldBody.renderBodies(ctx);
}

void ContactListener::BeginContact(b2Contact *contact) {
    Entity* e1 = (Entity *) contact->GetFixtureA()->GetBody()->GetUserData().pointer;
    Entity* e2 = (Entity *) contact->GetFixtureB()->GetBody()->GetUserData().pointer;
    if (e1 != nullptr && e2 != nullptr) {
        e1->onEntityCollision(*e2);
        e2->onEntityCollision(*e1);
    }
    if (e1 != nullptr) {
        e1->onCollision();
    }
    if (e2 != nullptr) {
        e2->onCollision();
    }
}

void ContactListener::EndContact(b2Contact *contact) {
    Entity* e1 = (Entity *) contact->GetFixtureA()->GetBody()->GetUserData().pointer;
    Entity* e2 = (Entity *) contact->GetFixtureB()->GetBody()->GetUserData().pointer;
    if (e1 != nullptr && e2 != nullptr) {
        e1->onEntityRelease(*e2);
        e2->onEntityRelease(*e1);
    }
    if (e1 != nullptr) {
        e1->onRelease();
    }
    if (e2 != nullptr) {
        e2->onRelease();
    }
}

void World::setGround(WorldBody *worldBody) {
    delete this->worldBody;
    this->worldBody = worldBody;
}