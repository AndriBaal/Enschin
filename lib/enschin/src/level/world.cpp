#include <enschin/world.h>

World::World(Vec2 gravity) {
    world->SetGravity(gravity.toB2());
    world->SetContactListener(this->contactListener);
}

void World::update(const UContext& ctx) {
    world->Step(ctx.deltaTime, 6, 2);
}

void World::renderBackground(const RContext& ctx) {

}

void World::renderForeground(const RContext& ctx) {
    for (auto& t: terrains) {
        ctx.renderer.translate(t.offset);
        for (int i = 0; i < t.terrain.getAmountOfElements(); i ++) {
            ctx.renderer.renderRainbow(*t.terrain.getElements()[i].model, ctx.totalTime);
        }
        ctx.renderer.translate(-t.offset);
    }
}

unsigned int World::addTerrain(Terrain& terrain, Vec2 positionOffSet) {

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(positionOffSet.x, positionOffSet.y);
    b2Body* groundBody = world->CreateBody(&groundBodyDef);
    std::cout << terrain.getChainShape()->GetChildCount() << std::endl;

    groundBody->CreateFixture(terrain.getChainShape(), 0.0f);

    terrains.push_back(WorldComponent{
        groundBody,
        terrain,
        positionOffSet
    });
    return terrains.size()-1;
}

void World::removeTerrain(unsigned int id) {
    world->DestroyBody(terrains.at(id).body);
    //terrains.erase(terrains.begin() + id);
}

void ContactListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold) {
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

void ContactListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse) {
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