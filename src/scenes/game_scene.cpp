#include <game/game_scene.h>

GameScene::GameScene(const GContext& ctx) : Scene(ctx, "./ressources/test_ressources.json") {
    input = Input("./settings/input/events/events.json");
    world.setGravity({0, -15});
    world.addTerrain(res.getTerrain("test_terrain"),{2, -5});

    UContext updateContext = Scene::getUpdateContext(ctx);

    Player* p = new Player(updateContext, {02.f, 3});
    entities.push_back(p);

    camera.setCameraTarget(p);
}

void GameScene::update(const GContext& ctx) {
    Scene::update(ctx);
}

void GameScene::render(const GContext& ctx) {
    Scene::render(ctx);
}