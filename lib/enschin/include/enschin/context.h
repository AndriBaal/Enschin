#pragma once
#include "ressources.h"
#include "input.h"
#include "timer.h"
#include "renderer.h"
#include "camera.h"
#include <box2d/b2_world.h>

/**
 * @brief Update context
 */
struct UpdateContext {
    const float deltaTime = 0;
    const float totalTime = 0;
    const Vec2 windowSize;
    const Input& input;
    const Ressources& res;
    Camera& camera;
    World& world;
};

/**
 * @brief Render context
 */
struct RenderContext {
    Renderer& renderer;
    const Camera& camera;
    const Vec2 windowSize;
    const float deltaTime = 0;
    const float totalTime = 0;
};