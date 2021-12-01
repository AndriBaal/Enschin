#include <game/game_scene.h>

GameScene::GameScene(Ressources* res, Input* input, const GameContext& ctx) : Scene(res, input, ctx) {
    for (float i = 0; i < 100; i++) {
        world.addTerrain(res->getTerrain("test_terrain"), res->getColor("green"), {i*35, -5});
    }

    UpdateContext updateContext = Scene::getUpdateContext(ctx);

    Player* p = new Player(updateContext, {02.f, 3});
    GameObject* g = new GameObject(updateContext,res->getModel("crate"), res->getColor("yellow"), {2, 6});
    entities.push_back(p);
    entities.push_back(g);

    camera.setCameraTarget(p);
}

void GameScene::update(const GameContext& ctx) {
    Scene::update(ctx);
}

void GameScene::render(const GameContext& ctx) {
    Scene::render(ctx);
}