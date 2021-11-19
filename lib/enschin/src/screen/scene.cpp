#include <enschin/scene.h>

Scene::Scene(Game& game) {
    renderer = Renderer(game.getWindow().getSize());
}

void Scene::updateTimers(float deltaTime) {
    for (auto & timer : timers) {
        if (timer->isActive() && Timer::isActiveAll()){
            timer->update(deltaTime);
        }
    }
}

void Scene::free() {
    res.free();
    for (auto i = entities.begin(); i < entities.end(); i++)
        delete *i;
    for (auto i = timers.begin(); i < timers.end(); i++)
        delete *i;
}