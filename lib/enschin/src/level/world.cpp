#include <enschin/world.h>

World::World(Vec2 gravity) {
    world.SetGravity(gravity.toB2());
    world.SetContactListener(this->contactListener);
}

World::~World() {

}

void World::update(const UpdateContext& ctx) {
    world.Step(ctx.deltaTime, 6, 2);
}

void World::renderBackground(const RenderContext& ctx) const{

}

void World::renderGround(const RenderContext& ctx) const{
    for (auto& t: terrains) {
        ctx.renderer.translate(t->offset);
        for (int i = 0; i < t->terrain->getAmountOfElements(); i++) {
            if (ctx.inScreen(t->terrain->getElements()[i]->getCollisionShape(), t->body))
                ctx.renderer.renderColor(t->terrain->getElements()[i], t->terrainColor);
        }
        ctx.renderer.translate(-t->offset);
    }
}

void World::renderForeground(const RenderContext &ctx) const {

}

unsigned int World::addTerrain(const Terrain* terrain, const Color* color, Vec2 positionOffSet) {
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(positionOffSet.x, positionOffSet.y);
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    groundBody->CreateFixture(terrain->getChainShape(), 0.0f);

    terrains.push_back(new WorldComponent {
        groundBody,
        terrain,
        color,
        positionOffSet
    });
    return terrains.size()-1;
}

void World::removeTerrain(unsigned int id) {
    world.DestroyBody(terrains.at(id)->body);
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