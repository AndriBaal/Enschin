#pragma once
#include "vec2.h"
#include "model.h"
#include "renderer.h"
#include "context.h"
#include "game_object.h"
#include "terrain.h"
#include <box2d/box2d.h>

class ContactListener : public b2ContactListener {
    void PreSolve(b2Contact *contact, const b2Manifold *oldManifold) override;
    void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse) override;
};

struct WorldComponent {
    b2Body* body;
    const Terrain* terrain;
    Vec2 offset;
};

class World{
private:
    std::vector<WorldComponent*> terrains;
    b2World world = b2World({0, -10});
    ContactListener* contactListener = new ContactListener();

public:
    World(Vec2 gravity = {0, -12.0f});
    ~World();
    unsigned int addTerrain(const Terrain* terrain, const Color* color, Vec2 positionOffset={0, 0});
    void removeTerrain(unsigned int id);
    void update(const UpdateContext& ctx);
    void renderBackground(const RenderContext& ctx) const;
    void renderGround(const RenderContext& ctx) const;
    void renderForeground(const RenderContext& ctx) const;
    b2World& getWorld() { return world; }
    void setGravity(Vec2 newGravity) { world.SetGravity(newGravity.toB2()); }
    Vec2 getGravity(){ return world.GetGravity(); }
};

