#include <game/player.h>

Player::Player(Scene& scene, Ressources& res, Vec2 pos)
    : Entity(res.getModel("test_model"), res.getSprite("bird")){
    timer = new Timer(0, sprite.getAmountOfSprites(), sprite.getFps(), true);
    scene.addTimer(timer);
    scene.addTimer(t = new Timer(0, 1, 1, 1));
}

void Player::update(Game& game, Scene& scene) {
    mousePos = scene.getInput().getCursorPos();
}

void Player::render(Game& game, Renderer& r) {
    r.translateAndRenderTexture(model, sprite.getTexture(timer->getValue()), mousePos);
    r.translate({-0.5f, -0.5f});
    r.rotate(45.0f);
    r.scale({2, 2});
    Color c = {0, 0, 1};
    r.renderRainbow(model, game.getTotalTime());
    r.scale({0.5, 0.5});
    r.rotate(-45.0f);
    r.translate({0.5f, 0.5f});
}