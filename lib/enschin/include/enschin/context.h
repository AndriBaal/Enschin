#pragma once

#include "ressources.h"
#include "input.h"
#include "timer.h"
#include "renderer.h"
#include "camera.h"
#include "window.h"
#include "level.h"


class Level;
/**
 * @brief Update context
 */
struct UpdateContext {
    const float deltaTime = 0;
    const float totalTime = 0;
    const Window& window;
    const Input &input;
    const Ressources &res;
    Level& level;
    Camera &camera;
};

/**
 * @brief Render context
 */
struct RenderContext {
    Renderer &renderer;
    const Camera& camera;
    const Window& window;
    const float deltaTime = 0;
    const float totalTime = 0;
};