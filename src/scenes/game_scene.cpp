#include <game/game_scene.h>

GameScene::GameScene(Game &game) : Scene(game) {
    res = Ressources("./ressources/test_ressources.json");
    input = Input("./settings/input/events/events.json");

    Player* p = new Player(*this, res, {02.f, 1});
    c.setCameraTarget(p->getPosAddress());

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -4.0f);
    groundBody = world.CreateBody(&groundBodyDef);

    groundBody->CreateFixture(&res.getModel("world_model").getCollisionShape(), 0.0f);
}

void GameScene::update(Game& game) {
    Scene::update(game);
}

void GameScene::render(Game& game) {
    Scene::render(game);
    c.update(renderer);
    for (auto i = entities.begin(); i != entities.end(); i++)
        (*i)->render(game, renderer);
    renderer.translate({groundBody->GetPosition().x, groundBody->GetPosition().y});
    Color co = Color{1, 0, 0, 1};
    renderer.renderRainbow(res.getModel("world_model"), game.getTotalTime());
    renderer.translate({-groundBody->GetPosition().x, -groundBody->GetPosition().y});
    c.reset(renderer);
}