#include <enschin/scene.h>

Scene::Scene(Ressources* res, Input* input, const GameContext& ctx)
    : res(*res), input((Input &) *input) {
    renderer = Renderer(ctx.windowSize);
}

Scene::~Scene() {
    //delete res;
    for (auto e : entities)
        delete e;
    entities.clear();
    for (auto t : timers)
        delete t;
    timers.clear();
}

void Scene::updateTimers(float deltaTime) {
    for (auto & timer : timers) {
        if (timer->isActive() && Timer::isActiveAll()){
            timer->update(deltaTime);
        }
    }
}

void Scene::update(const GameContext& ctx) {
    updateTimers(ctx.deltaTime);
    updateInput(ctx.window);
    const UpdateContext updateContext = getUpdateContext(ctx);
    for (auto e = entities.begin(); e < entities.end(); e++){
        if ((*e)->isDead()){
            delete (*e);
            entities.erase(e);
        }else {
            (*e)->update(updateContext);
        }
    }

    world.update(updateContext);
}

void Scene::render(const GameContext& ctx) {
    const RenderContext renderContext = getRenderContext(ctx);
    world.renderBackground(renderContext);
    camera.update(renderer);
    for (auto & entity : entities)
        entity->render(renderContext);
    world.renderForeground(renderContext);
    camera.reset(renderer);
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

UpdateContext Scene::getUpdateContext(const GameContext& ctx) {
    return {
        ctx.deltaTime,
        ctx.totalTime,
        ctx.windowSize,
        input,
        res,
        world.getWorld(),
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