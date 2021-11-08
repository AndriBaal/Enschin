#pragma once
#include <chrono>
#include "enschin/screen/window.h"
#include "enschin/screen/scene.h"
#include "enschin/graphics/renderer.h"
#include "enschin/util/ressources.hpp"
#include "enschin/input/input.h"

class Scene;
/**
 * @brief Main class of Enschin. Innherit from this class to start
 * a new game.
 */
class Game {
protected:
	Scene* currentScene;
	Ressources* currentRessources;
	Window window;
	Input input;
private:
	long long firstTime, secondTime, lastTime;
	long long getNanos();
	float deltaTime, fps;
	bool running = false;
public:
	Game(std::string gameName, Dim2 windowSize, bool fullscreen);
    void init();
	virtual void start() = 0;
	virtual void loop() = 0;
    virtual void free() = 0;
	float getDeltaTime() const{ return deltaTime; }
	float getFps(){ return fps; }
	Window& getWindow(){ return window; }
    Input& getInput() { return input; }
};