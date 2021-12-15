#pragma once

#include "window.h"
#include "scene.h"
#include "renderer.h"
#include "ressources.h"
#include "input.h"
#include "game_context.h"


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
    std::string gameName;
public:
    Game(std::string gameName, Vec2i windowSize, bool fullscreen);

    void init();
    virtual void start(const GameContext &gtx) = 0;
    virtual void loop(const GameContext &gtx) = 0;
    virtual void free();
    float getDeltaTime() const { return deltaTime; }
    float getTotalTime() const { return totalTime; }
    float getFps() { return fps; }
    Window &getWindow() { return window; }
};