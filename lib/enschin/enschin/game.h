#pragma once
#include <chrono>
#include "enschin/screen/window.h"
#include "enschin/screen/scene.h"
#include "enschin/graphics/renderer.h"
#include "enschin/util/ressources.hpp"

class Scene;
class Window;
/**
 * @brief Main class of Enschin. Innherit from this class to start
 * a new game.
 */
class Game {
protected:
	Scene* currentScene;
	Ressources* currentRessources;
private:
	long long firstTime, secondTime, lastTime;
	long long getNanos();
	float deltaTime, fps;
	bool running = false;
	Window* window;
public:
	Game(std::string gameName, Dim2 windowSize, bool fullscreen);
	virtual void start(Scene& startScene, Ressources& startRessources);
	virtual void loop() = 0;
	float getDeltaTime(){ return deltaTime; }
	float getFps(){ return fps; }
	Window& getWindow(){ return *window; }
};