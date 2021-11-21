#pragma once
#include <vector>
#include <box2d/b2_world.h>
#include <box2d/b2_body.h>
#include "renderer.h"
#include "input.h"
#include "game.h"
#include "ressources.h"
#include "timer.h"
#include "entity.h"
#include "camera.h"

/**
 * @brief Scenes that are meant to be used for different environments
 * For example between loading & game screen or for different rooms.
 */
class Entity;
class Game;
class Scene {
protected:
    Ressources res;
	Renderer renderer;
	Input input;
    Camera c = Camera(&Vec2::nullVec2);
    Vec2 gravity = {0, -10.f};
    b2World world = (b2Vec2(0, -10.0));
//    Model* groundModel;
    b2Body* groundBody;
    std::vector<Entity*> entities;
//    std::vector<GameObject*> gameObjects;
//    std::vector<GuiObject*> guiObjects;
    void free();
private:
    std::vector<Timer*> timers;
public:
	Scene(Game& game);
    ~Scene(){ free(); }
	virtual void update(Game& game);
	virtual void render(Game& game);
	Renderer& getRenderer(){ return renderer; }

    void addTimer(Timer* timer);
    void removeTimer(Timer* timer);
    void updateTimers(float deltaTime);
	void updateInput(GLFWwindow* window);

    void setGravity(Vec2 gravity);
    Vec2 getGravity(){ return gravity; }

	Input& getInput() { return input; }

	b2World& getWorld(){ return world; }
}; 