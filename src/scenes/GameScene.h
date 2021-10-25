#pragma once
#include <enschin/screen/Window.h>
#include <enschin/screen/Scene.hpp>
#include <enschin/graphics/Renderer.h>
#include <enschin/graphics/Model.h>
#include <enschin/graphics/Renderer.h>
#include <enschin/graphics/Texture.h>
#include <enschin/objects/Entity.h>
#include <enschin/input/Mouse.h>
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
	GameScene();
	virtual void update() override;
	virtual void render() override;
};