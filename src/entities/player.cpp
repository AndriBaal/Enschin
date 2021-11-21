#include <game/player.h>

Player::Player(Scene& scene, Ressources& res, Vec2 pos)
    : Entity(scene, res.getModel("test_model"), res.getSprite("cute"), pos){
    timer = new Timer(0, sprite.getAmountOfSprites(), sprite.getFps(), true);
    scene.addTimer(timer);
}

void Player::update(Game& game, Scene& scene) {
    mousePos = scene.getInput().getCursorPos();
    if (scene.getInput().getEvent("walk_forward")){
        body->ApplyForce({0, 100}, body->GetPosition(), 1);
    }
    if (scene.getInput().getEvent("walk_backwards")) {
        body->ApplyForce({0, -100}, body->GetPosition(), 1);
    }
    if (scene.getInput().getEvent("walk_left")) {
        body->ApplyForce({-10, 0}, body->GetPosition(), 1);
    }
    if (scene.getInput().getEvent("walk_right")) {
        body->ApplyForce({10, 0}, body->GetPosition(), 1);
    }
}

void Player::render(Game& game, Renderer& r) {
    r.translateAndRenderTexture(model, sprite.getTexture(), {body->GetPosition().x, body->GetPosition().y}, body->GetAngle());
    r.translate({-25.f, -25.f});
    r.rotate(45.0f);
    r.scale({2, 2});
    Color c = {0, 0, 1};
    r.renderRainbow(model, game.getTotalTime());
    r.scale({0.5, 0.5});
    r.rotate(-45.0f);
    r.translate({25.f, 25.f});
}