#pragma once

#include <vector>
#include "renderer.h"
#include "input.h"
#include "common_ressources.h"
#include "timer.h"
#include "camera.h"
#include "level.h"
#include "context.h"
#include "game_context.h"


/**
 * @brief Scenes that are meant to be used for different environments
 * For example between loading & game screen or for different rooms.
 */
class Scene {
protected:
    const CommonResources &commonRes;
    Input &input;
    Level *level;
    Renderer renderer;
    Camera camera;
    RenderContext getRenderContext(const GameContext &ctx);
    UpdateContext getUpdateContext(const GameContext &ctx);
private:
public:
    Scene(const GameContext &ctx, CommonResources *res, Input *input, float fov = 5.0f);
    ~Scene();
    void update(const GameContext &ctx);
    void render(const GameContext &ctx);
    Camera &getCamera() { return camera; }
};