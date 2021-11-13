#pragma once
#include <enschin/game.h>
#include <enschin/screen/window.h>
#include <enschin/screen/scene.h>
#include <enschin/graphics/renderer.h>
#include <enschin/graphics/model.h>
#include <enschin/graphics/renderer.h>
#include <enschin/graphics/texture.h>
#include <enschin/objects/entity.h>
#include <enschin/input/mouse.h>
#include <enschin/util/camera.hpp>
#include <iostream>
#include <vector>

class GameScene : public Scene {
private:
	std::vector<Entity> entities;
	Vec2 mousePos = Vec2();
    Timer t = Timer(this, 0.0f, 2.0f, 1.0f, &value);;
    Camera cam = Camera(renderer, mousePos);
    float value;
public:
	GameScene(Game& game);
    void init(Game& game);
	virtual void update(Game& game, Ressources& ressources) override;
	virtual void render(Ressources& ressources) override;
};