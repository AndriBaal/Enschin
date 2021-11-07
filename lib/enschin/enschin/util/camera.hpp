#pragma once
#include "enschin/graphics/renderer.h"
#include "enschin/math/vec2.h"

class Camera {
private:
    Vec2* cameraTarget;
    Renderer* renderer;
public:
    Camera() = default;
    Camera(Renderer& renderer, Vec2& cameraTarget) : cameraTarget(&cameraTarget), renderer(&renderer){}
    void update() { renderer->translate(*cameraTarget); }
    void reset() { renderer->translate(-*cameraTarget); }
    Vec2& getCameraTarget() { return *cameraTarget; }
    void setCameraTarget(Vec2 *cameraTarget) { cameraTarget = cameraTarget; }
};