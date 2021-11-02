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
	std::vector<Entity> entities;
	Vec2 mousePos = Vec2();
	Texture* texi;
public:
	GameScene(Game& game);
	virtual void update(Game& game, Ressources& ressources) override;
	virtual void render(Ressources& ressources) override;
};