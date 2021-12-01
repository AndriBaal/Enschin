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
    const Ressources& res;
    Input& input;
    Renderer renderer;
    World world;
    Camera camera;
    std::vector<GameObject*> entities;
//    std::vector<GameObject*> gameObjects;
//    std::vector<GuiObject*> guiObjects;
private:
    std::vector<Timer*> timers;
public:
	Scene(Ressources* res, Input* input, const GameContext& ctx);
    ~Scene();
	virtual void update(const GameContext& ctx);
	virtual void render(const GameContext& ctx);
    Renderer& getRenderer(){ return renderer; }

    void addTimer(Timer* timer);
    void removeTimer(Timer* timer);
    void updateTimers(float deltaTime);
	void updateInput(GLFWwindow* window);
    UpdateContext getUpdateContext(const GameContext& ctx);
    RenderContext getRenderContext(const GameContext& ctx);
};