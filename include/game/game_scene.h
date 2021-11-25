#pragma once
#include <enschin/scene.h>
#include "player.h"
#include <iostream>
#include <enschin/camera.h>

class GameScene : public Scene {
private:

public:
	GameScene(const GContext& ctx);
    ~GameScene(){ free(); }
    void update(const GContext& ctx) override;
    void render(const GContext& ctx) override;
};