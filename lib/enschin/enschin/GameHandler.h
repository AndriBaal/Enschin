#pragma once
#include <GLFW/glfw3.h>
#include "Window.h"
#include "graphics/Scene.hpp"
#include <chrono>


class GameHandler
{
private:
	long long firstTime, secondTime, lastTime;
	long long getNanos();

public:
	float deltaTime, fps;
	Scene* currentScene;
	Window* window;
	int* io;
	virtual void start(Window* window, Scene& startScene);
	virtual void updateCurrentScene();
};