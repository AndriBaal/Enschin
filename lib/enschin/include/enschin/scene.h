#pragma once
#include <vector>
#include "renderer.h"
#include "input.h"
#include "ressources.h"
#include "timer.h"
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
    World* world = new World();
    Renderer renderer;
    Camera camera;
    ComponentManager componentManager;
private:
    RenderContext getRenderContext(const GameContext& ctx);
public:
	Scene(Ressources* res, Input* input, const GameContext& ctx, float fov = 5.0f);
    ~Scene();
    void update(const GameContext& ctx);
    void render(const GameContext& ctx);
    virtual void updateComponents(const UpdateContext& ctx);
    virtual void renderComponents(const RenderContext& ctx);


    Camera& getCamera(){ return camera; }
    UpdateContext getUpdateContext(const GameContext& ctx);
};