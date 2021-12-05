#pragma once
#include <enschin/scene.h>
#include "player.h"
#include <iostream>
#include <enschin/camera.h>

class GameScene : public Scene {
private:

public:
	GameScene(Ressources* res, Input* input, const GameContext& ctx);
};