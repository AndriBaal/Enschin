#pragma once
#include "vec2.h"
#include "model.h"
#include "renderer.h"
#include "context.h"
#include "entity.h"
#include "terrain.h"
#include <box2d/box2d.h>

class ContactListener : public b2ContactListener {
    void PreSolve(b2Contact *contact, const b2Manifold *oldManifold) override;
    void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse) override;
};

struct WorldComponent {
    b2Body* body;
    Terrain& terrain;
    Vec2 offset;
};

class World{
private:
    std::vector<WorldComponent> terrains;
    b2World* world = new b2World({0, -10});
    ContactListener* contactListener = new ContactListener();
public:
    World(Vec2 gravity = {0, -12.0f});
    unsigned int addTerrain(Terrain& terrain, Vec2 positionOffset={0, 0});
    void removeTerrain(unsigned int id);
    void update(const UContext& ctx);
    void renderBackground(const RContext& ctx);
    void renderForeground(const RContext& ctx);
    b2World& getWorld() { return *world; }
    void setGravity(Vec2 newGravity) { world->SetGravity(newGravity.toB2()); }
    Vec2 getGravity(){ return world->GetGravity(); }
};

