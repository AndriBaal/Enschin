#pragma once
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>
#include <string>
#include <iostream>
#include "context.h"
#include "vec2.h"
#include "sprite.h"
#include "model.h"

struct UContext;
struct RContext;
class Entity {
protected:
    float scale = 1;
    const Model& model;
    const SpriteSheet& sprite;
    b2Body* body;
private:
    static unsigned int idCounter;
    unsigned int id;
	float health = 100;
	float maxHealth = 100;
    float friction;
    float density;
    float updateRadius = 10.0f;

    bool dead = false;
    float deathDelay = 0.0f;
    //TODO
//    bool visible, updatable, disabled;
    bool onGround = true;
    bool fixedRotation = false;
public:
	Entity(const UContext& ctx, const Model& model, const SpriteSheet& sprite, Vec2 pos={0, 0}, float density=1.0f, float friction=0.3f, bool fixedRotation=false);
	~Entity();
	virtual void update(const UContext& ctx) = 0;
	virtual void render(const RContext& ctx) = 0;
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
    void applyForce(const b2Vec2& force){ applyForce(force, body->GetPosition()); }
    void applyForce(const b2Vec2& force, const b2Vec2& point){ body->ApplyForce(force, point); }
    float getUpdateRadius(){ return updateRadius; }

    bool isDead(){ return dead; }
    void setDead(bool dead){ this->dead = dead; };
};