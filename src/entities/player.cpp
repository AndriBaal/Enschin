#include "player.h"

Player::Player(Ressources& res, Vec2 pos, Dim2 dim, Vec2 dir):Entity(res, pos, dim, dir) {
    model = res.getModel("test_model");
    sprite = res.getSpriteSheet("test_texture");
}

void Player::update(Game& game, Scene& scene) {

}

void Player::render(Renderer& r) {
    r.translateAndRenderTexture(model, sprite.getTexture(), mousePos);
    r.translate({-0.5f, -0.5f});
    r.rotate(45.0f);
    r.renderRainbow(model, 12);
    r.rotate(-45.0f);
    r.translate({0.5f, 0.5f});
}