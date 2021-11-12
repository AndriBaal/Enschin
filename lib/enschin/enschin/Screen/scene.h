#pragma once
#include <vector>
#include "enschin/graphics/renderer.h"
#include "enschin/input/input.h"
#include "enschin/game.h"
#include "enschin/util/ressources.h"
#include "enschin/util/timer.h"

/**
 * @brief Scenes that are meant to be used for different environments
 * For example between loading & game screen or for different rooms.
 */
class Timer;
class Game;
class Scene {
protected:
	Renderer renderer;
	Input input;
private:
    std::vector<Timer*> timers;
public:
	Scene(Game& game);
	virtual void update(Game& game, Ressources& ressources) = 0;
	virtual void render(Ressources& ressources) = 0;
	Renderer& getRenderer(){ return renderer; }

    void removeTimer(Timer* timer){ timers.erase(std::remove(timers.begin(), timers.end(), timer), timers.end()); }
    void addTimer(Timer* timer){ timers.push_back(timer); }
    void updateTimers(float deltaTime);
	void updateInput(){ input.update(renderer.getUnits()); }
	Input& getInput() { return input; }
}; 