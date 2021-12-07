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
    bool inScreen(const b2Shape* collisionShape, const b2Body* body) const {
        b2PolygonShape windowShape;
        windowShape.SetAsBox(camera.getFov() * camera.getRatio(), camera.getFov());
        Vec2 camPos = camera.getCameraPosition();
        b2Transform cameraTransform = {{camPos.x, camPos.y}, b2Rot(0)};
        return b2TestOverlap(collisionShape, 0, &windowShape, 0, body->GetTransform(), cameraTransform);
    }
};