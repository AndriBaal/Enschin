#pragma once
#include <enschin/Window.h>
#include <enschin/graphics/Scene.hpp>
#include <enschin/graphics/Model.h>
#include <enschin/graphics/Renderer.h>
#include <enschin/graphics/Renderer.h>
#include <enschin/graphics/Texture.h>
#include <iostream>

class Texture;

class GameScene : public Scene
{
private:
	Model* m;
	Texture* texi;
public:
	GameScene();
	virtual void update() override;
	virtual void render() override;
};