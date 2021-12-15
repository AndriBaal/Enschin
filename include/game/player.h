#pragma once
#include <enschin/game_object.h>
#include <enschin/timer.h>

class Player : public GameObject{
private:
    Vec2f mousePos;
    Timer* jumpTimer;
    short jumps = 2;
    short maxJumps = 2;
public:
    Player(const UpdateContext& ctx, Vec2f pos);
	void update(const UpdateContext& ctx) override;
    void onCollision(const GameObject* go = nullptr) override;
};