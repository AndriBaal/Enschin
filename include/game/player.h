#pragma once
#include <enschin/entity.h>

class Player : public Entity{
private:
    Vec2 mousePos;
    Timer* jumpTimer;
    short jumps = 2;
    short maxJumps = 2;
public:
    Player(Scene& scene, Ressources& res, Vec2 pos);
	void update(Game& game, Scene& scene) override;
    void render(Game& game, Renderer& r) override;
    void onEntityCollision(Entity& entity) override;
    void onCollision() override;
    void onRelease() override;
//	virtual void onDamage(float damage) override;
//	virtual void onDeath() override;
//	virtual void onAttack() override;
};