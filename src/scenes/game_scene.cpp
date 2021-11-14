#include "game_scene.h"

GameScene::GameScene(Game &game) : Scene(game) {
    ressources = new Ressources("./ressources/test_ressources.json");
    entities.push_back(new Player(*ressources, {}, {}, {}));
}

void GameScene::update() {
    for (auto i = entities.begin(); i < entities.end(); i++) {
        (*i)->update(game, *this);
    }
}

void GameScene::render() {
    for (auto i = entities.begin(); i != entities.end(); i++) {
        (*i)->render(renderer);
    }
}