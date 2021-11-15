#pragma once
#include <enschin/screen/scene.h>
#include "entities/player.h"
#include <iostream>

class GameScene : public Scene {
private:
	std::vector<Entity*> entities;
public:
	GameScene(Game& game);
    ~GameScene(){ free(); }
	virtual void update() override;
	virtual void render() override;
};