#pragma once
#include <string>
#include "enschin/game.h"
#include "enschin/math/dim2.h"
#include "enschin/math/vec2.h"
#include "enschin/graphics/sprite.h"
#include "enschin/graphics/model.h"
#include <iostream>

class Game;
class Entity {
protected:
    Vec2 pos;
    Vec2 dir;
    Dim2 dim;
    float scale;
    Model model;
    SpriteSheet sprite;
private:
    static unsigned int idCounter;
    unsigned int id;
	float health;
	float maxHealth;
public:
	Entity(Ressources& res, Vec2 pos = {}, Dim2 dim = {}, Vec2 dir = {});
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