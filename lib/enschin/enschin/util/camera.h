#pragma once
#include "enschin/graphics/renderer.h"
#include "enschin/math/vec2.h"

class Camera {
private:
    Vec2& cameraTarget;
public:
    Camera() = default;
    Camera(Vec2& cameraTarget);
    void update(Renderer&);
    void reset(Renderer&);
    Vec2& getCameraTarget() { return cameraTarget; }
    void setCameraTarget(Vec2 cameraTarget) { cameraTarget = cameraTarget; }
};