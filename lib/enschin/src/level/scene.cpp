#include <enschin/scene.h>

Scene::Scene(const GameContext& ctx, CommonResources* res, Input* input, float fov)
    : commonRes(*res), input(*input) {
    camera.setFov(ctx.window.getSize(), fov);
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
    input.update(ctx.window.getGlfw(), renderer.getFov());
    const UpdateContext updateContext = getUpdateContext(ctx);
    level->getChunkManager().update(updateContext);
    level->getWorld().Step(ctx.deltaTime, 6, 2);
}

void Scene::render(const GameContext& ctx) {
    const RenderContext renderContext = getRenderContext(ctx);
    renderer.resetMatrix();
    camera.update(renderer);
    level->getChunkManager().render(renderContext);
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
            ctx.window,
            input,
            commonRes,
            *level,
            camera,
    };
}

RenderContext Scene::getRenderContext(const GameContext& ctx) {
    return {
        renderer,
        camera,
        ctx.window,
        ctx.deltaTime,
        ctx.totalTime
    };
}