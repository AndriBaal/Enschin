#pragma once
#include <enschin/entity.h>
#include <enschin/timer.h>

class Player : public Entity{
private:
    Vec2 mousePos;
    Timer* jumpTimer;
    short jumps = 7;
    short maxJumps = 7;
public:
    Player(const UpdateContext& ctx, Vec2 pos);
	void update(const UpdateContext& ctx) override;
    void render(const RenderContext& ctx) override;
    void onEntityCollision(Entity& entity) override;
    void onCollision() override;
    void onRelease() override;
//	virtual void onDamage(float damage) override;
//	virtual void onDeath() override//
//	virtual void onAttack() override;
};