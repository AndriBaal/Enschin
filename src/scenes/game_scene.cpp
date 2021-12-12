#include <game/game_scene.h>

GameScene::GameScene(Ressources* res, Input* input, const GameContext& ctx) : Scene(res, input, ctx, 5) {
    world = new World({100, 100}, {10, 10});
    UpdateContext updateContext = Scene::getUpdateContext(ctx);

    world->addTerrain(updateContext,res->getTerrain("test_terrain"), res->getColor("green"), {0, -5});

    new Player(updateContext, {0, 10});
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
