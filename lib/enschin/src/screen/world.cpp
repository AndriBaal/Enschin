 #include <enschin/world.h>

World::World(Model& model, Vec2 worldPos, Vec2 gravity)
    : worldModel(&model), worldPos(worldPos){

    world.SetGravity(gravity.toB2());
    world.SetContactListener(this->contactListener);
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(worldPos.x, worldPos.y);
    groundBody = world.CreateBody(&groundBodyDef);

    groundBody->CreateFixture(model.getCollisionShape(), 0.0f);
}

void World::update(Game& game, Scene& scene) {
    world.Step(game.getDeltaTime(), velocityIterations, positionIterations);
}

b2Body* World::addBody(b2BodyDef* bodyDef) {
    return world.CreateBody(bodyDef);
}

void World::renderBackground(Game& game, Renderer &r) {
    r.translate(groundBody->GetPosition());
    r.renderRainbow(*worldModel, game.getTotalTime());
    r.translate(-groundBody->GetPosition());
}

void World::renderForeground(Game& game, Renderer &r) {

}

void ContactListener::BeginContact(b2Contact *contact) {
//    (Entity) contact->GetFixtureA()->GetBody()->GetUserData();
}

void ContactListener::EndContact(b2Contact *contact) {

}
