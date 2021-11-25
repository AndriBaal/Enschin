#pragma once
#include "renderer.h"
#include "entity.h"
#include "box2d/b2_math.h"

class Camera {
private:
    b2Vec2* cameraTarget;
public:
    Camera() = default;
    Camera(b2Vec2* vec2);
    void update(Renderer&);
    void reset(Renderer&);
    Vec2* getCameraTarget() { return reinterpret_cast<Vec2 *>(cameraTarget); }
    void setCameraTarget(Vec2* cameraTarget) { this->cameraTarget = reinterpret_cast<b2Vec2 *>(cameraTarget); }
};