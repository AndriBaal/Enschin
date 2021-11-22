#pragma once
#include "vec2.h"
#include "model.h"
#include "renderer.h"
#include <box2d/box2d.h>

class World{
private:
    Vec2 worldPos;
    Model* worldModel;
    b2World world = b2World({0, -10});
    b2Body* groundBody;
    unsigned int velocityIterations = 6;
    unsigned int positionIterations = 2;
public:
    World() = default;
    World(Model& model, Vec2 worldPos,Vec2 gravity = {0, -12.0f});
    void update(float deltaTime);
    void renderBackground(Renderer& renderer);
    void renderForeground(Renderer& renderer);
    b2Body* addBody(b2BodyDef* bodyDef);
    void setGravity(Vec2 newGravity){ world.SetGravity(newGravity.toB2()); }
    Vec2 getGravity(){ return world.GetGravity(); }
};