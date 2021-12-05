#include <enschin/camera.h>

Camera::Camera(b2Body* cameraTarget) : cameraTarget(cameraTarget) {
    cameraMode = BODY;
}

Camera::Camera(Vec2 cameraPosition) : cameraPosition(cameraPosition){
    cameraMode = POSITION;
}

void Camera::update(Renderer& r) {
    if (cameraMode == BODY) {
        cameraPosition = cameraTarget->GetPosition();
    }
    r.translate(-cameraPosition);
}

void Camera::reset(Renderer& r) {
    if (cameraMode == BODY) {
        cameraPosition = cameraTarget->GetPosition();
    }
    r.translate(cameraPosition);
}

void Camera::fade(Vec2 pos, float time) {

}

void Camera::fade(b2Body *body, float time) {

}

Vec2 Camera::getCameraPosition(){
    if (cameraMode == BODY) {
        return cameraTarget->GetPosition();
    } else {
        return cameraPosition;
    }
}
void Camera::setCameraTarget(b2Body* cameraTarget) {
    this->cameraTarget = cameraTarget;
    cameraMode = BODY;
}
void Camera::setCameraPosition(Vec2 position){
    this->cameraPosition = cameraPosition;
    cameraMode = POSITION;
}

void Camera::setFov(float newFov) {
    if (newFov > maxFov)
        fov = maxFov;
    else if (newFov < minFov)
        fov = minFov;
    else
        fov = newFov;
}

void Camera::increaseFov(float increasingFov) {
    if (fov + increasingFov > maxFov)
        fov = maxFov;
    else if (fov + increasingFov < minFov)
        fov = minFov;
    else
        fov = fov + increasingFov;
}