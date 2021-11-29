#include <game/game_scene.h>

GameScene::GameScene(Ressources* res, Input* input, const GameContext& ctx) : Scene(res, input, ctx) {
    world.addTerrain(res->getTerrain("test_terrain"),{2, -5});

    UpdateContext updateContext = Scene::getUpdateContext(ctx);

    Player* p = new Player(updateContext, {02.f, 3});
    entities.push_back(p);

    camera.setCameraTarget(p);
}

void GameScene::update(const GameContext& ctx) {
    Scene::update(ctx);
}

void GameScene::render(const GameContext& ctx) {
    Scene::render(ctx);
}