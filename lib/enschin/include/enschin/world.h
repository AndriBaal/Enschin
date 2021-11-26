#pragma once
#include "vec2.h"
#include "model.h"
#include "renderer.h"
#include "context.h"
#include "entity.h"
#include <box2d/box2d.h>

class ContactListener : public b2ContactListener {
    void BeginContact(b2Contact* contact) override;
    void EndContact(b2Contact* contact) override;
};

class World{
private:
    Model* worldModel;
    b2World world = b2World({0, -10});
    b2Body* groundBody;
    ContactListener* contactListener = new ContactListener();
public:
    World() = default;
    World(Model& model, Vec2 worldPos, Vec2 gravity = {0, -12.0f});
    void update(const UContext& ctx);
    void renderBackground(const RContext& ctx);
    void renderForeground(const RContext& ctx);
    b2World& getWorld() { return world; }
    b2Body* addBody(b2BodyDef* bodyDef);
    void setGravity(Vec2 newGravity){ world.SetGravity(newGravity.toB2()); }
    Vec2 getGravity(){ return world.GetGravity(); }
};

