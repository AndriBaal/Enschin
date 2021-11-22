#pragma once

#include "window.h"
#include "scene.h"
#include "renderer.h"
#include "ressources.h"
#include "input.h"

class Scene;

/**
 * @brief Main class of Enschin. Innherit from this class to start
 * a new game.
 */
class Game {
protected:
    Scene *currentScene;
    Window window;
private:
    double firstTime, secondTime;
    double lastTime = 0;
    float deltaTime, fps, totalTime;
    bool running = false;
public:
    Game(std::string gameName, Vec2 windowSize, bool fullscreen);
    void init();
    virtual void start() = 0;
    virtual void loop() = 0;
    virtual void free() = 0;
    float getDeltaTime() const { return deltaTime; }
    float getTotalTime() const { return totalTime; }
    float getFps() { return fps; }
    Window &getWindow() { return window; }
};