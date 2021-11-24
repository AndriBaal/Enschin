#include <game/game_scene.h>

GameScene::GameScene(Game &game) : Scene(game) {
    res = Ressources("./ressources/test_ressources.json");
    input = Input("./settings/input/events/events.json");
    world = new World(res.getModel("world_model"), {0, -2.f}, {0, -18});

    Player* p = new Player(*this, res, {02.f, 1});
    camera.setCameraTarget((Vec2 *) &p->getBody().GetPosition());
}

void GameScene::update(Game& game) {
    Scene::update(game);
}

void GameScene::render(Game& game) {
    Scene::render(game);
}