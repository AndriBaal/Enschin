#pragma once

#include "ressources.h"
#include "input.h"
#include "timer.h"
#include "renderer.h"
#include "camera.h"
#include "chunk_manager.h"
#include <box2d/b2_world.h>


class ChunkManager;
/**
 * @brief Update context
 */
struct UpdateContext {
    const float deltaTime = 0;
    const float totalTime = 0;
    const Vec2 windowSize;
    const Input &input;
    const Ressources &res;
    ChunkManager &chunkManager;
    Camera &camera;
    b2World &world;
};

/**
 * @brief Render context
 */
struct RenderContext {
    Renderer &renderer;
    const Camera& camera;
    const Vec2 windowSize;
    const float deltaTime = 0;
    const float totalTime = 0;
};