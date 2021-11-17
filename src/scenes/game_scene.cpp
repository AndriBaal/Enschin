#include <game/game_scene.h>

GameScene::GameScene(Game &game) : Scene(game) {
    res = Ressources("./ressources/test_ressources.json");
    input = Input("./settings/input/events/events.json");
    entities.push_back(new Player(*this, res, {0, 0}));
}

void GameScene::update() {
    for (auto i = entities.begin(); i < entities.end(); i++)
        (*i)->update(game, *this);
}

void GameScene::render() {
    for (auto i = entities.begin(); i != entities.end(); i++)
        (*i)->render(game, renderer);
}