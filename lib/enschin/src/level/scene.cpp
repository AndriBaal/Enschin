#include <enschin/scene.h>

Scene::Scene(Ressources* res, Input* input, const GameContext& ctx, float fov)
    : res(*res), input((Input &) *input) {
    camera.setFov(ctx.windowSize, fov);
    renderer = Renderer(fov, camera.getRatio());
}

Scene::~Scene() {
//    for (auto t : timers)
//        delete t;
//    timers.clear();
}

//void Scene::updateTimers(float deltaTime) {
//    for (auto & timer : timers)
//        if (timer->isActive() && Timer::isActiveAll())
//            timer->update(deltaTime);
//
//}

void Scene::update(const GameContext& ctx) {
    if (renderer.getFov() != camera.getFov() || renderer.getRatio() != camera.getRatio())
        renderer.resetProjection(camera.getFov(), camera.getRatio());
    //updateTimers(ctx.deltaTime);
    input.update(ctx.window, renderer.getFov());
    const UpdateContext updateContext = getUpdateContext(ctx);
    world->getChunkManager()->update(updateContext);
    world->update(updateContext);
}

void Scene::render(const GameContext& ctx) {
    const RenderContext renderContext = getRenderContext(ctx);
    renderer.resetMatrix();
    Scene::renderComponents(renderContext);
}

void Scene::renderComponents(const RenderContext &ctx) {
    camera.update(renderer);
    camera.reset(renderer);
}

//void Scene::removeTimer(Timer *timer) {
//    timers.erase(std::remove(timers.begin(), timers.end(), timer), timers.end());
//}
//
//void Scene::addTimer(Timer* timer){
//    timers.push_back(timer);
//}

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
    };
}

RenderContext Scene::getRenderContext(const GameContext& ctx) {
    return {
        renderer,
        camera,
        ctx.windowSize,
        ctx.deltaTime,
        ctx.totalTime
    };
}