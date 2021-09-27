#pragma once
#include "Window.h"
#include "graphics/Scene.hpp"
#include <chrono>
#include "graphics/Renderer.h"

class Window;
class GameHandler
{
private:
	long long firstTime, secondTime, lastTime;
	long long getNanos();
	Window* window;
	Renderer* renderer;

public:
	float deltaTime, fps;
	Scene* currentScene;
	int* io;
	virtual void start(Scene* startScene, Renderer* renderer);
	virtual void update() = 0;
};