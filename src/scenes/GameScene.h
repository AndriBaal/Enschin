#pragma once
#include <enschin/Window.h>
#include <enschin/graphics/Scene.hpp>
#include <enschin/graphics/Model.h>
#include <enschin/graphics/Renderer.h>
#include <enschin/graphics/Renderer.h>
#include <enschin/graphics/Texture.h>
#include <enschin/objects/Entity.h>
#include <iostream>
#include <vector>

class Texture;

class GameScene : public Scene
{
private:
	Model* m;
	Texture* texi;
	std::vector<Entity> entities;
public:
	GameScene();
	virtual void update() override;
	virtual void render(Renderer* renderer) override;
};