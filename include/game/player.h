#pragma once
#include <enschin/entity.h>
#include <enschin/timer.h>

class Player : public Entity{
private:
    Vec2 mousePos;
    Timer* jumpTimer;
    short jumps = 2;
    short maxJumps = 2;
public:
    Player(const UContext& ctx, Vec2 pos);
	void update(const UContext& ctx) override;
    void render(const RContext& ctx) override;
    void onEntityCollision(Entity& entity) override;
    void onCollision() override;
    void onRelease() override;
//	virtual void onDamage(float damage) override;
//	virtual void onDeath() override;
//	virtual void onAttack() override;
};