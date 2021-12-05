#include <enschin/scene.h>

Scene::Scene(Ressources* res, Input* input, const GameContext& ctx, float fov)
    : res(*res), input((Input &) *input) {
    camera.setFov(fov);
    renderer = Renderer(ctx.windowSize, fov);
}

Scene::~Scene() {
    for (auto t : timers)
        delete t;
    timers.clear();
}

void Scene::updateTimers(float deltaTime) {
    for (auto & timer : timers)
        if (timer->isActive() && Timer::isActiveAll())
            timer->update(deltaTime);

}

void Scene::update(const GameContext& ctx) {
    updateTimers(ctx.deltaTime);
    input.update(ctx.window, renderer.getFov());
    const UpdateContext updateContext = getUpdateContext(ctx);
    updateComponents(updateContext);
    componentManager.removeDeadObjects();
    world->update(updateContext);
    if (renderer.getFov() != camera.getFov())
        renderer.setFov(camera.getFov());
}

void Scene::render(const GameContext& ctx) {
    const RenderContext renderContext = getRenderContext(ctx);
    renderer.resetMatrix();
    Scene::renderComponents(renderContext);
}

void Scene::updateComponents(const UpdateContext &ctx) {
    for (auto& g : componentManager.getGameObjects())
        if (g->isActive())
            g->update(ctx);
}

void Scene::renderComponents(const RenderContext &ctx) {
    world->renderBackground(ctx);
    camera.update(renderer);
    world->renderGround(ctx);
    for (auto & g : componentManager.getGameObjects())
        if (g->isVisible())
            g->render(ctx);
    world->renderForeground(ctx);
    camera.reset(renderer);
}

void Scene::removeTimer(Timer *timer) {
    timers.erase(std::remove(timers.begin(), timers.end(), timer), timers.end());
}

void Scene::addTimer(Timer* timer){
    timers.push_back(timer);
}

UpdateContext Scene::getUpdateContext(const GameContext& ctx) {
    return {
        ctx.deltaTime,
        ctx.totalTime,
        ctx.windowSize,
        input,
        res,
        camera,
        componentManager,
        world->getWorld(),
        timers
    };
}

RenderContext Scene::getRenderContext(const GameContext& ctx) {
    return {
        renderer,
        ctx.deltaTime,
        ctx.totalTime
    };
}