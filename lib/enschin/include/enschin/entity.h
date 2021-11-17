#pragma once
#include <string>
#include "enschin/game.h"
#include "dim2.h"
#include "vec2.h"
#include "sprite.h"
#include "model.h"
#include <iostream>

class Scene;
class Game;
class Entity {
protected:
    Vec2 pos;
    Vec2 dir;
    float scale = 1;
    Model& model;
    SpriteSheet& sprite;
private:
    static unsigned int idCounter;
    unsigned int id;
	float health = 100;
	float maxHealth = 100;
public:
	Entity(Model& model, SpriteSheet& sprite);
	~Entity();
	virtual void update(Game& game, Scene& scene) = 0;
	virtual void render(Game&, Renderer& r) = 0;
//	virtual void onEntityCollision() = 0;
//	virtual void onDamage(float damage) = 0;
//	virtual void onDeath() = 0;
//	virtual void onAttack() = 0;

    void setPos(Vec2 newPos){ pos = newPos; }
    Vec2 getPos() { return pos; };
    void increasePos(Vec2 increment) { pos += increment; }

};