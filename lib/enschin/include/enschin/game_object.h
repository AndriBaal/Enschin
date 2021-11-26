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

class GameObject{
protected:
    float friction = 0.3f;
    float density = 1.0f;
    const Model& model;
    const SpriteSheet& sprite;
    b2Body* body;
    bool visible = true;
    bool collision = true;
    bool fixedRotation = false;
public:
    GameObject(const UContext& ctx, const Model& model, const SpriteSheet& sprite,Vec2 pos, float density = 1.0f, float friction = 0.3f, bool visible=true, bool collision=true, bool fixedRotation=false);
    void applyForce(const b2Vec2& force){ applyForce(force, body->GetPosition()); }
    void applyForce(const b2Vec2& force, const b2Vec2& point){ body->ApplyForce(force, point); }

    bool isVisible(){ return visible; }
    void SetVisible(bool visible){ this->visible = visible; }

    bool isCollision(){ return collision; }
    void setCollision(bool collision){ this->collision = collision; }

    bool isFixedRotation(){ return fixedRotation; }
    void setFixedRotation(bool fixedRotation){ this->fixedRotation = fixedRotation; }

    b2Body& getBody(){ return *body; }
};