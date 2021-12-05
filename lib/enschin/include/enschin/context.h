#pragma once
#include "ressources.h"
#include "input.h"
#include "timer.h"
#include "renderer.h"
#include "component_manager.h"
#include "camera.h"
#include <box2d/b2_world.h>

struct ComponentManager;
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
    ComponentManager& componentManager;
    b2World& world;
    std::vector<Timer*>& timers;
};

/**
 * @brief Render context
 */
struct RenderContext {
    Renderer& renderer;
    const float deltaTime = 0;
    const float totalTime = 0;
};