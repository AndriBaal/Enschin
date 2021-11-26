#pragma once
#include "renderer.h"
#include "game_object.h"
#include "box2d/b2_math.h"

class Camera {
private:
    GameObject* cameraTarget;
public:
    Camera() = default;
    Camera(GameObject* cameraTarget);
    void update(Renderer&);
    void reset(Renderer&);
    GameObject& getCameraTarget() { return *cameraTarget; }
    void setCameraTarget(GameObject* cameraTarget) { this->cameraTarget = cameraTarget; }
};