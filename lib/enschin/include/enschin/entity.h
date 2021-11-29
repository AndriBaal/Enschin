#pragma once
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>
#include <string>
#include <iostream>
#include "game_object.h"
#include "context.h"
#include "vec2.h"
#include "sprite.h"
#include "model.h"

class Entity : public GameObject{
protected:
	float health = 100;
	float maxHealth = 100;
    float updateRadius = 10.0f;

    bool dead = false;
    float deathDelay = 0.0f;
public:
	Entity(const UpdateContext& ctx, const Model& model, const SpriteSheet& sprite, Vec2 pos={0, 0}, float density=1.0f, float friction=0.3f, bool fixedRotation=false);
	~Entity();
	virtual void update(const UpdateContext& ctx) = 0;
	virtual void render(const RenderContext& ctx) = 0;
    virtual void onEntityCollision(Entity& otherEntity) = 0;
    virtual void onEntityRelease(Entity& otherEntity) {}
    virtual void onCollision() = 0;
    virtual void onRelease(){}
//	virtual void onDamage(float damage) = 0;
//	virtual void onDeath() = 0;
//	virtual void onAttack() = 0;

    b2Body& getBody(){ return *body; }

    Vec2 getPos() { return body->GetPosition(); }
    float getRotation(){ return body->GetAngle(); }

    float getUpdateRadius(){ return updateRadius; }

    bool isDead(){ return dead; }
    void setDead(bool dead){ this->dead = dead; };
};