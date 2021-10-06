#pragma once
#include <enschin/objects/Entity.h>

class Player : public Entity{
private:

public:
    Player(std::string tag, Vector2 pos, Dimension dim, Vector2 dir);
	virtual void update() override;
	virtual void render() override;
	virtual void onEntityCollision() override;
	virtual void onDamage(float damage) override;
	virtual void onDeath() override;
	virtual void onAttack() override;
};