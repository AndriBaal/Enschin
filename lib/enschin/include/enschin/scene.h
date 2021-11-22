#pragma once
#include <vector>
#include "renderer.h"
#include "input.h"
#include "game.h"
#include "ressources.h"
#include "timer.h"
#include "entity.h"
#include "camera.h"
#include "world.h"

/**
 * @brief Scenes that are meant to be used for different environments
 * For example between loading & game screen or for different rooms.
 */
class Entity;
class Game;
class World;
class Scene {
protected:
    Ressources res;
	Renderer renderer;
	Input input;
    World* world;
    Camera camera = Camera(&Vec2::nullVec2);
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

	Input& getInput() { return input; }
    void addEntity(Entity* entity) { entities.push_back(entity); }

    World& getWorld(){ return *world; }
}; 