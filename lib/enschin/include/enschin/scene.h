#pragma once
#include <vector>
#include "renderer.h"
#include "input.h"
#include "ressources.h"
#include "timer.h"
#include "entity.h"
#include "camera.h"
#include "world.h"
#include "context.h"
#include "game_context.h"


/**
 * @brief Scenes that are meant to be used for different environments
 * For example between loading & game screen or for different rooms.
 */
class Scene {
protected:
    const Ressources res;
    Input input;
    Renderer renderer;
    World world;
    Camera camera;
    std::vector<Entity*> entities;
//    std::vector<GameObject*> gameObjects;
//    std::vector<GuiObject*> guiObjects;
    void free();
private:
    std::vector<Timer*> timers;
public:
	Scene(const GContext& ctx, std::string ressourcePath);
    ~Scene();
	virtual void update(const GContext& ctx);
	virtual void render(const GContext& ctx);
    Renderer& getRenderer(){ return renderer; }

    void addTimer(Timer* timer);
    void removeTimer(Timer* timer);
    void updateTimers(float deltaTime);
	void updateInput(GLFWwindow* window);
    UContext getUpdateContext(const GContext& ctx);
    RContext getRenderContext(const GContext& ctx);
};