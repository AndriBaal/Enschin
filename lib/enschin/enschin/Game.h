#pragma once
#include <chrono>
#include "enschin/screen/Window.h"
#include "enschin/screen/Scene.hpp"
#include "enschin/graphics/Renderer.h"

class Window;
/**
 * @brief Main class of Enschin. Innherit from this class to start
 * a new game.
 * 
 */
class Game {
protected:
	Window* window;

private:
	long long firstTime, secondTime, lastTime;
	long long getNanos();
	float deltaTime, fps;

public:
	Game() = default;
	Scene* currentScene;
	virtual void start(Window* window, Scene* startScene);
	virtual void loop() = 0;
	float getDeltaTime(){ return deltaTime; }
	float getFps(){ return fps; }
};