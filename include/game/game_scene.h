#pragma once
#include <enschin/scene.h>
#include "player.h"
#include <iostream>
#include <enschin/camera.h>

class GameScene : public Scene {
private:
	std::vector<Entity*> entities;
    Camera c;
public:
	GameScene(Game& game);
    ~GameScene(){ free(); }
	void update(Game& game) override;
	void render(Game& game) override;
};