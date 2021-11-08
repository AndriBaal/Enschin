#include "scene.h"

Scene::Scene(Game& game) { 
    renderer = Renderer(game.getWindow().getSize());
}

void Scene::updateTimers(float deltaTime) {
    for (auto timer = timers.begin(); timer != timers.end(); timer++) {
        if ((*timer)->isActive() && (*timer)->isActiveAll())
            (*timer)->update(deltaTime);
    }
}