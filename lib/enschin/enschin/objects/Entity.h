#pragma once
#include <string>
#include "../math/Dimension.h"
#include "../math/vectors.h"
#include <iostream>

class Entity
{
private:
	std::string tag;
	float health;
	float maxHealth;
public:
	Vector2 pos;
	Vector2 dir;
	Dimension dim;
	Entity(std::string tag, Vector2 pos = {}, Dimension dim = {}, Vector2 dir = {});
	~Entity();
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void onEntityCollision() = 0;
	virtual void onDamage(float damage) = 0;
	virtual void onDeath() = 0;
	virtual void onAttack() = 0;
};