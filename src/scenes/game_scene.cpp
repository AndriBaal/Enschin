#include <game/game_scene.h>

GameScene::GameScene(Game &game) : Scene(game) {
    res = Ressources("./ressources/test_ressources.json");
    input = Input("./settings/input/events/events.json");
    Player* p = new Player(*this, res, {0, 0});
    entities.push_back(p);
    c = Camera(p->getPosAsPointer());
}

void GameScene::update(Game& game) {
    //move in default scene update function
    for (auto i = entities.begin(); i < entities.end(); i++)
        (*i)->update(game, *this);
    //Implement automatic collssion detection
    for (entities) {

    }
}

void GameScene::render(Game& game) {
    //move in default scene render function
    c.update(renderer);
    for (auto i = entities.begin(); i != entities.end(); i++)
        (*i)->render(game, renderer);
    c.reset(renderer);
}