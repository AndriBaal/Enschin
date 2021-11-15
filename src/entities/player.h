#pragma once
#include <enschin/components/entity.h>

class Player : public Entity{
private:
    Vec2 mousePos;
public:
    Player(Ressources& res, Vec2 pos, Dim2 dim, Vec2 dir);
	virtual void update(Game& game, Scene& scene) override;
    virtual void render(Game&, Renderer& r) override;
//	virtual void onEntityCollision() override;
//	virtual void onDamage(float damage) override;
//	virtual void onDeath() override;
//	virtual void onAttack() override;
};