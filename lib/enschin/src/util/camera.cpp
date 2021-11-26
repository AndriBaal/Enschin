#include <enschin/camera.h>

Camera::Camera(GameObject* cameraTarget) : cameraTarget(cameraTarget) {}

void Camera::update(Renderer& r) {
    r.translate(-cameraTarget->getBody().GetPosition());
}

void Camera::reset(Renderer& r) {
    r.translate(cameraTarget->getBody().GetPosition());
}