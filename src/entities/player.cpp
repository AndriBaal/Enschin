#include "player.h"

Player::Player(Ressources& res, Vec2 pos, Dim2 dim, Vec2 dir):Entity(res, pos, dim, dir) {
    model = res.getModel("test_model");
    sprite = res.getSpriteSheet("test_sheet");
}

void Player::update(Game& game, Scene& scene) {
    mousePos = scene.getInput().getCursorPos();
}

void Player::render(Game& game, Renderer& r) {
    r.translateAndRenderTexture(model, sprite.getTexture(5), mousePos);
    r.translate({-0.5f, -0.5f});
    r.rotate(45.0f);
    r.scale({2, 2});
    r.renderRainbow(model, game.getTotalTime());
    r.scale({0.5, 0.5});
    r.rotate(-45.0f);
    r.translate({0.5f, 0.5f});
}