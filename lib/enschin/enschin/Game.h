#pragma once
#include <chrono>
#include "enschin/screen/window.h"
#include "enschin/screen/scene.h"
#include "enschin/graphics/renderer.h"

class Scene;
class Window;
/**
 * @brief Main class of Enschin. Innherit from this class to start
 * a new game.
 * 
 */
class Game {
protected:

private:
	long long firstTime, secondTime, lastTime;
	long long getNanos();
	float deltaTime, fps;
	Window* window;

public:
	Game(std::string gameName, Dim2 windowSize, bool fullscreen);
	Scene* currentScene;
	virtual void start(Scene& startScene);
	virtual void loop() = 0;
	float getDeltaTime(){ return deltaTime; }
	float getFps(){ return fps; }
	Window& getWindow(){ return *window; }
};