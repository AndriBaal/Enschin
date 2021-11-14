#pragma once
#include <vector>
#include "enschin/graphics/renderer.h"
#include "enschin/input/input.h"
#include "enschin/game.h"
#include "enschin/util/ressources.h"
#include "enschin/util/timer.h"
#include "enschin/components/entity.h"

/**
 * @brief Scenes that are meant to be used for different environments
 * For example between loading & game screen or for different rooms.
 */
 class Entity;
class Timer;
class Game;
class Scene {
protected:
    Game& game;
    Ressources* ressources;
	Renderer renderer;
	Input input;
    std::vector<Entity*> entities;
private:
    std::vector<Timer*> timers;
public:
	Scene(Game& game);
    ~Scene();
	virtual void update() = 0;
	virtual void render() = 0;
	Renderer& getRenderer(){ return renderer; }

    void removeTimer(Timer* timer){ timers.erase(std::remove(timers.begin(), timers.end(), timer), timers.end()); }
    void addTimer(Timer* timer){ timers.push_back(timer); }
    void updateTimers(float deltaTime);
	void updateInput(){ input.update(renderer.getUnits()); }
	Input& getInput() { return input; }
}; 