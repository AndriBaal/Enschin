#pragma once
#include <vector>
#include "enschin/game.h"
#include "enschin/graphics/renderer.h"
#include "enschin/util/ressources.hpp"
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
private:
    std::vector<Timer*> timers;
public:
	Scene(Game& game);
	virtual void update(Game& game, Ressources& ressources) = 0;
	virtual void render(Ressources& ressources) = 0;
    void updateTimers(float deltaTime);
	Renderer& getRenderer(){ return renderer; }
}; 