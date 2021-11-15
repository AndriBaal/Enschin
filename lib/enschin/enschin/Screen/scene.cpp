#include "scene.h"

Scene::Scene(Game& game) : game(game){
    renderer = Renderer(game.getWindow().getSize());
    input = Input(game.getWindow().getGlfw());
}

void Scene::updateTimers(float deltaTime) {
    for (auto timer = timers.begin(); timer != timers.end(); timer++) {
        if ((*timer)->isActive() && (*timer)->isActiveAll()){
            (*timer)->update(deltaTime);
        }
    }
}

void Scene::free() {
    ressources->free();
    for (auto i = entities.begin(); i < entities.end(); i++)
        delete *i;
    for (auto i = timers.begin(); i < timers.end(); i++)
        delete *i;
}