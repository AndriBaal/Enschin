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

void Scene::update(Game &game) {
    updateTimers(game.getDeltaTime());
    updateInput(game.getWindow().getGlfw());
    world->update(game, *this);
    for (auto i = entities.begin(); i < entities.end(); i++)
        (*i)->update(game, *this);
}

void Scene::render(Game &game) {
    world->renderBackground(game, renderer);
    camera.update(renderer);
    for (auto & entity : entities)
        entity->render(game, renderer);
    world->renderForeground(game, renderer);
    camera.reset(renderer);
}

void Scene::free() {
    res.free();
    for (auto i = entities.begin(); i < entities.end(); i++)
        delete *i;
    for (auto i = timers.begin(); i < timers.end(); i++)
        delete *i;
}

void Scene::updateInput(GLFWwindow *window) {
    input.update(window, renderer.getUnits());
}

void Scene::removeTimer(Timer *timer) {
    timers.erase(std::remove(timers.begin(), timers.end(), timer), timers.end());
}

void Scene::addTimer(Timer *timer) {
    timers.push_back(timer);
}