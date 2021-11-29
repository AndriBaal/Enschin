#pragma once
#include <enschin/scene.h>
#include "player.h"
#include <iostream>
#include <enschin/camera.h>

class GameScene : public Scene {
private:

public:
	GameScene(Ressources* res, Input* input, const GameContext& ctx);
    void update(const GameContext& ctx) override;
    void render(const GameContext& ctx) override;
};