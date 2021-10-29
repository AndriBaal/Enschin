#pragma once
#include "enschin/game.h"
#include "enschin/screen/window.h"
#include "enschin/screen/scene.h"
#include "enschin/graphics/renderer.h"
#include "enschin/graphics/model.h"
#include "enschin/graphics/renderer.h"
#include "enschin/graphics/texture.h"
#include "enschin/objects/entity.h"
#include "enschin/input/mouse.h"
#include <iostream>
#include <vector>

class GameScene : public Scene {
private:
	Model* m;
	Model m1;
	Texture* texi;
	std::vector<Entity> entities;
	Vec2 mousePos = Vec2();
public:
	GameScene(Game& game);
	virtual void update(Game& game, Window& window) override;
	virtual void render() override;
};