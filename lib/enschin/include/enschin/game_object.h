#pragma once
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>
#include <string>
#include <iostream>
#include "game_object.h"
#include "vec2.h"
#include "sprite.h"
#include "model.h"
#include "context.h"

enum RenderType {
    COLOR, SPRITE, SHADER
};

class GameObject{
private:
    b2World* world;
    RenderType renderType;
protected:
    float friction = 0.3f;
    float density = 1.0f;
    const Model* model;
    const SpriteSheet* sprite;
    const Color* color;
    b2Body* body;
    bool visible = true;
    bool active = true;
    bool collision = true;
    bool fixedRotation = false;
public:
    GameObject(const UpdateContext& ctx, const Model* model, const SpriteSheet* sprite, Vec2 pos,float density = 1.0f, float friction = 0.3f, bool collision=true, bool fixedRotation=false);
    GameObject(const UpdateContext& ctx, const Model* model, const Color* c, Vec2 pos, float density = 1.0f, float friction = 0.3f, bool collision=true, bool fixedRotation=false);
    GameObject(const UpdateContext& ctx, const Model* model, Vec2 pos, float density = 1.0f, float friction = 0.3f, bool collision=true, bool fixedRotation=false);
    ~GameObject();

    void createBody(const UpdateContext& ctx, Vec2 pos, float density, float friction, bool collision, bool fixedRotation);

    virtual void update(const UpdateContext& ctx);
    virtual void render(const RenderContext& ctx);

    void applyForce(const b2Vec2& force){ applyForce(force, body->GetPosition()); }
    void applyForce(const b2Vec2& force, const b2Vec2& point){ body->ApplyForce(force, point); }

    bool isVisible(){ return visible; }
    void setVisible(bool visible){ this->visible = visible; }

    bool isActive(){ return active; }
    void setActive(bool active){ this->active = active; }

    bool isCollision(){ return collision; }
    void setCollision(bool collision){ this->collision = collision; }


    bool isFixedRotation(){ return fixedRotation; }
    void setFixedRotation(bool fixedRotation){ this->fixedRotation = fixedRotation; }

    b2Body& getBody(){ return *body; }
};