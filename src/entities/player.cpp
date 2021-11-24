#include <game/player.h>

Player::Player(Scene& scene, Ressources& res, Vec2 pos)
    : Entity(scene, res.getModel("test_model"), res.getSprite("cute"), pos, 1.0f){
    jumpTimer = new Timer(0, .25f);
    scene.addTimer(jumpTimer);
}

void Player::update(Game& game, Scene& scene) {
    mousePos = scene.getInput().getCursorPos();
    if (scene.getInput().getEvent("walk_forward") && jumps && jumpTimer->take()){
        if (jumps >= 1){
            body->SetLinearVelocity({body->GetLinearVelocity().x, 0});
            body->ApplyForce({0, 1400}, body->GetPosition());
        }else{
            body->ApplyForce({0, 1000}, body->GetPosition());
        }
        jumps--;
    }
    if (scene.getInput().getEvent("walk_backwards")) {
        body->ApplyForce({0, -1000}, body->GetPosition());
    }
    if (scene.getInput().getEvent("walk_left")) {
        body->ApplyForce({-25, 0}, body->GetPosition());
    }
    if (scene.getInput().getEvent("walk_right")) {
        body->ApplyForce({25, 0}, body->GetPosition());
    }
}

void Player::render(Game& game, Renderer& r) {
    r.translateAndRenderTexture(model, sprite.getTexture(), body->GetPosition(), body->GetAngle());
}

void Player::onRelease() {
}

void Player::onCollision() {
    jumps = maxJumps;
}

void Player::onEntityCollision(Entity &entity) {

}