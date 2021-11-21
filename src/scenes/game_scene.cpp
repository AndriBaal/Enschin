#include <game/game_scene.h>

GameScene::GameScene(Game &game) : Scene(game) {
    res = Ressources("./ressources/test_ressources.json");
    input = Input("./settings/input/events/events.json");
    Player* p = new Player(*this, res, {0, 0});
    entities.push_back(p);
    c = Camera(p->getPosAddress());
}

void GameScene::update(Game& game) {
    Scene::update(game);
}

void GameScene::render(Game& game) {
    Scene::render(game);
}