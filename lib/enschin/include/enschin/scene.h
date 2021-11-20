#pragma once
#include <vector>
#include <box2d/b2_world.h>
#include "renderer.h"
#include "input.h"
#include "enschin/game.h"
#include "ressources.h"
#include "timer.h"
#include "entity.h"

/**
 * @brief Scenes that are meant to be used for different environments
 * For example between loading & game screen or for different rooms.
 */
class Entity;
class Timer;
class Game;
class Scene {
protected:
    Ressources res;
	Renderer renderer;
	Input input;
    Vec2 gravity = {0, -10.f};
    b2World world = (gravity.toBox());
    std::vector<Entity*> entities;
    void free();
private:
    std::vector<Timer*> timers;
public:
	Scene(Game& game);
    ~Scene(){ free(); }
	virtual void update(Game& game) = 0;
	virtual void render(Game& game) = 0;
	Renderer& getRenderer(){ return renderer; }

    void addTimer(Timer* timer){ timers.push_back(timer); }
    void removeTimer(Timer* timer){ timers.erase(std::remove(timers.begin(), timers.end(), timer), timers.end());}
    void updateTimers(float deltaTime);
	void updateInput(GLFWwindow* window){ input.update(window, renderer.getUnits()); }
    void setGravity(Vec2 gravity){ this->gravity = gravity; world = (gravity.toBox()); }
    Vec2 getGravity(){ return gravity; }
	Input& getInput() { return input; }
}; 