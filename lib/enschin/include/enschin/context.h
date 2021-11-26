#pragma once
#include "ressources.h"
#include "input.h"
#include "timer.h"
#include "renderer.h"
#include <box2d/b2_world.h>

/**
 * @brief Update context
 */
struct UContext {
    const float deltaTime = 0;
    const float totalTime = 0;
    const Vec2 windowSize;
    const Input& input;
    const Ressources& res;
    b2World& world;
    std::vector<Timer*>& timers;
};

/**
 * @brief Render context
 */
struct RContext {
    Renderer& renderer;
    const float deltaTime = 0;
    const float totalTime = 0;
};