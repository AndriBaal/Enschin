#include <enschin/scene.h>

#include <utility>

Scene::Scene(const GContext& ctx, std::string ressourcePath)
    : res(std::move(ressourcePath)) {
    renderer = Renderer(ctx.windowSize);
}

Scene::~Scene() {
    free();
}

void Scene::updateTimers(float deltaTime) {
    for (auto & timer : timers) {
        if (timer->isActive() && Timer::isActiveAll()){
            timer->update(deltaTime);
        }
    }
}

void Scene::update(const GContext& ctx) {
    updateTimers(ctx.deltaTime);
    updateInput(ctx.window);
    const UContext updateContext = getUpdateContext(ctx);
    for (auto e = entities.begin(); e < entities.end(); e++){
        if ((*e)->isDead()){
            delete (*e);
            entities.erase(e);
        }else {
            (*e)->update(updateContext);
        }
    }

    world->update(updateContext);
}

void Scene::render(const GContext& ctx) {
    const RContext renderContext = getRenderContext(ctx);
    world->renderBackground(renderContext);
    camera.update(renderer);
    for (auto & entity : entities)
        entity->render(renderContext);
    world->renderForeground(renderContext);
    camera.reset(renderer);
}

void Scene::free() {
    delete world;
    res.free();
    for (auto e : entities)
        delete e;
    entities.clear();
    for (auto t : timers)
        delete t;
    timers.clear();
}

void Scene::updateInput(GLFWwindow *window) {
    input.update(window, renderer.getUnits());
}

void Scene::removeTimer(Timer *timer) {
    timers.erase(std::remove(timers.begin(), timers.end(), timer), timers.end());
}

void Scene::addTimer(Timer* timer){
    timers.push_back(timer);
}

UContext Scene::getUpdateContext(const GContext& ctx) {
    return {
        ctx.deltaTime,
        ctx.totalTime,
        ctx.windowSize,
        input,
        res,
        world->getWorld(),
        entities,
        timers
    };
}

RContext Scene::getRenderContext(const GContext& ctx) {
    return {
        renderer,
        ctx.deltaTime,
        ctx.totalTime
    };
}