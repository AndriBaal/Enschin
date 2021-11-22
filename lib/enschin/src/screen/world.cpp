#include <enschin/world.h>

World::World(Model& model, Vec2 worldPos, Vec2 gravity)
    : worldModel(&model), worldPos(worldPos){

    world.SetGravity(gravity.toB2());
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(worldPos.x, worldPos.y);
    groundBody = world.CreateBody(&groundBodyDef);

    groundBody->CreateFixture(model.getCollisionShape(), 0.0f);
}

void World::update(float deltaTime) {
    world.Step(deltaTime, velocityIterations, positionIterations);
}

b2Body* World::addBody(b2BodyDef* bodyDef) {
    return world.CreateBody(bodyDef);
}

void World::renderBackground(Renderer &renderer) {
    Color c = {0, 1, 0, 0};
    renderer.translate(groundBody->GetPosition());
    renderer.renderColor(*worldModel, c);
    renderer.translate(-groundBody->GetPosition());
}

void World::renderForeground(Renderer &renderer) {

}