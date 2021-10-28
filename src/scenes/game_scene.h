#pragma once
#include "enschin/Game.h"
#include "enschin/screen/Window.h"
#include "enschin/screen/Scene.h"
#include "enschin/graphics/Renderer.h"
#include "enschin/graphics/Model.h"
#include "enschin/graphics/Renderer.h"
#include "enschin/graphics/Texture.h"
#include "enschin/objects/Entity.h"
#include "enschin/input/mouse.h"
#include <iostream>
#include <vector>

class GameScene : public Scene {
private:
	Model* m;
	Model* m1;
	Texture* texi;
	std::vector<Entity> entities;
	Vec2 mousePos = Vec2();
public:
	GameScene(Game& game);
	virtual void update(Game& game, Window& window) override;
	virtual void render() override;
};