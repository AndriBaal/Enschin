#include <game/game_scene.h>

GameScene::GameScene(const GContext& ctx) : Scene(ctx, "./ressources/test_ressources.json") {
    input = Input("./settings/input/events/events.json");
    world = new World(res.getModel("world_model"), {0, -3.f}, {0, -10});

    UContext updateContext = Scene::getUpdateContext(ctx);

    Player* p = new Player(updateContext, {02.f, 1});
    entities.push_back(p);
}

void GameScene::update(const GContext& ctx) {
    Scene::update(ctx);
}

void GameScene::render(const GContext& ctx) {
    Scene::render(ctx);
}