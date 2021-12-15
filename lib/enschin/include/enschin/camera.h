#pragma once

#include "renderer.h"
#include "box2d/b2_body.h"


enum CameraMode {
    BODY, POSITION
};

class Camera {
private:
    CameraMode cameraMode;
    b2Body *cameraTarget;
    b2PolygonShape cameraShape;
    Vec2f cameraPosition;
    Vec2f fadePosition;
    float fov;
    float ratio;
    float minFov = 2.0f;
    float maxFov = 100.0f;
    bool fading = false;
public:
    Camera(b2Body *cameraTarget);

    Camera(Vec2f cameraTarget = {0, 0});

    void update(Renderer &);

    void reset(Renderer &);

    void fade(Vec2f pos, float time);

    void fade(b2Body *body, float time);

    void setMaxFov(float fov) { this->maxFov = fov; }

    void setMinFov(float fov) { this->minFov = fov; }

    float getFov() const { return fov; }

    float getRatio() const { return ratio; }

    void setFov(Vec2f windowSize, float newFov);

    void increaseFov(Vec2f windowSize, float increasingFov);

    b2Body &getCameraTarget() { return *cameraTarget; }

    Vec2f getCameraPosition() const;

    b2PolygonShape *getCameraShape() { return &cameraShape; }

    void setCameraTarget(b2Body *cameraTarget);

    void setCameraPosition(Vec2f position);
};