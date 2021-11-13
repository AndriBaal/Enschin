#include "game_scene.h"

GameScene::GameScene(Game& game) : Scene(game) {
    t.start();
}

void GameScene::update(Game& game, Ressources& ressources) {
    mousePos = input.getCursorPos();
}

void GameScene::render(Ressources& ressources) {
    renderer.translateAndRenderTexture(ressources.models.at("test_model"), ressources.textures.at("test_texture"), mousePos);
    renderer.translate({-0.5f, -0.5f});
    renderer.rotate(45.0f);
    renderer.renderTexture(ressources.models.at("test_model"), ressources.textures.at("test_texture"));
    renderer.rotate(-45.0f);
    renderer.translate({0.5f, 0.5f});
}