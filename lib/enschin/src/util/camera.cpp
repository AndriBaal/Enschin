#include <enschin/camera.h>

Camera::Camera(Vec2& cameraTarget) : cameraTarget(cameraTarget) {}

void Camera::update(Renderer& r) {
    r.translate(cameraTarget);
}

void Camera::reset(Renderer& r) {
    r.translate(-cameraTarget);
}