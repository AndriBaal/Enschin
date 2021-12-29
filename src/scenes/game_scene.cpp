#include <game/game_scene.h>

GameScene::GameScene(CommonResources* res, Input* input, const GameContext& ctx)
    : Scene(ctx, res, input, 5) {
    level = new Level({513, 21}, {10, 1500});
    UpdateContext updateContext = Scene::getUpdateContext(ctx);

    updateContext.window.setClearColor(Color{.7, 0.3,.8, 1});

    for (int i = 0; i < 2 ;i ++) {
        level->addTerrain(updateContext, res->getTerrain("test_terrain"), res->getColor("green"), {i * 50.0f, -5});
    }

    Player* p = new Player(updateContext, {1, 1});
    new GameObject(updateContext, "crate", res->getModel("crate"), res->getSprite("crate"), {-13, -2}, 0, 1, 0, 0);
    new GameObject(updateContext, "crate", res->getModel("crate"), res->getSprite("crate"), {-11.75, -1}, 0, 1, 0, 0);
    new GameObject(updateContext, "crate", res->getModel("crate"), res->getSprite("crate"), {-10.5, -2}, 0, 1, 0, 0);

    new GameObject(updateContext, "crate", res->getModel("crate"), res->getSprite("crate"), {-7, -2}, 0, 1, 1, 0);

    new GameObject(updateContext, "crate", res->getModel("crate"), res->getSprite("crate"), {-3, -1});
    new GameObject(updateContext, "crate", res->getModel("crate"), res->getSprite("crate"), {-1.75, 1});
    new GameObject(updateContext, "crate", res->getModel("crate"), res->getSprite("crate"), {-0.5, -1});

    new GameObject(updateContext, "ball", res->getModel("ball"), res->getColor("yellow"), {21, 2});
    new GameObject(updateContext, "ball", res->getModel("ball"), res->getColor("yellow"), {22, 2});
    new GameObject(updateContext, "ball", res->getModel("ball"), res->getColor("yellow"), {23, 2});
}
