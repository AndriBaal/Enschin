 #include <enschin/world.h>

World::World(Model& model, Vec2 worldPos, Vec2 gravity)
    : worldModel(&model){

    world.SetGravity(gravity.toB2());
    world.SetContactListener(this->contactListener);
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(worldPos.x, worldPos.y);
    groundBody = world.CreateBody(&groundBodyDef);

    groundBody->CreateFixture(model.getCollisionShape(), 0.0f);
}

void World::update(const UContext& ctx) {
    world.Step(ctx.deltaTime, 6.0, 2.0);
}

b2Body* World::addBody(b2BodyDef* bodyDef) {
    return world.CreateBody(bodyDef);
}

void World::renderBackground(const RContext& ctx) {
    ctx.renderer.translate(groundBody->GetPosition());
    ctx.renderer.renderRainbow(*worldModel, ctx.totalTime);
    ctx.renderer.translate(-groundBody->GetPosition());
}

void World::renderForeground(const RContext& ctx) {

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
