#pragma once
#include <string>
#include "../math/Dim.h"
#include "../math/Vec2.h"
#include <iostream>

class Entity {
private:
	std::string tag;
	float health;
	float maxHealth;
public:
	Vec2 pos;
	Vec2 dir;
	Dim dim;
	Entity(std::string tag, Vec2 pos = {}, Dim dim = {}, Vec2 dir = {})
		: tag(tag), pos(pos), dim(dim), dir(dir) {};
	~Entity();
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void onEntityCollision() = 0;
	virtual void onDamage(float damage) = 0;
	virtual void onDeath() = 0;
	virtual void onAttack() = 0;
};