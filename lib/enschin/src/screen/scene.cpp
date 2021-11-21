#include <enschin/scene.h>
#include <box2d/b2_polygon_shape.h>


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
    world.Step(game.getDeltaTime(), 6, 2);
    for (auto i = entities.begin(); i < entities.end(); i++)
        (*i)->update(game, *this);
}

void Scene::render(Game &game) {

}

void Scene::free() {
    res.free();
    for (auto i = entities.begin(); i < entities.end(); i++)
        delete *i;
    for (auto i = timers.begin(); i < timers.end(); i++)
        delete *i;
}

void Scene::setGravity(Vec2 gravity) {
    this->gravity = gravity;
//    world = (gravity.toBox());
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