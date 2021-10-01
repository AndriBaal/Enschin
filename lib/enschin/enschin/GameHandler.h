#pragma once
#include "Window.h"
#include "graphics/Scene.hpp"
#include <chrono>
#include "graphics/Renderer.h"

class Window;
class Renderer;
class GameHandler
{
protected:
	Window* window;
	Renderer* renderer;

private:
	long long firstTime, secondTime, lastTime;
	long long getNanos();
	float deltaTime, fps;

public:
	GameHandler() = default;
	Scene* currentScene;
	int* io;
	virtual void start(Window* window, Scene* startScene, Renderer* renderer);
	virtual void process() = 0;
	float getDeltaTime(){ return deltaTime; }
	float getFps(){ return fps; }
};