#pragma once
#include <enschin/entity.h>

class Player : public Entity{
private:
    Vec2 mousePos;
    Timer* timer;
    Timer* t;
public:
    Player(Scene& scene, Ressources& res, Vec2 pos);
	virtual void update(Game& game, Scene& scene) override;
    virtual void render(Game& game, Renderer& r) override;
//	virtual void onEntityCollision() override;
//	virtual void onDamage(float damage) override;
//	virtual void onDeath() override;
//	virtual void onAttack() override;
};