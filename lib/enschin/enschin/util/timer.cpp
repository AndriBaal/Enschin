#include "timer.h"

bool Timer::activeAll = true;

void Timer::startAll(){ activeAll=1; }
void Timer::stopAll(){ activeAll=0; }
bool Timer::isActiveAll() { return activeAll; }

Timer::Timer(Scene *scene, float startValue, float endValue, float incrementPerSecond, float *value, bool active)
    : scene(scene), startValue(startValue), endValue(endValue), incrementPerSecond(incrementPerSecond), value(value), active(active) {
    scene->addTimer(this);
    *value = startValue;
}

void Timer::update(float deltaTime) {
    *value += deltaTime * incrementPerSecond;
    if ((incrementPerSecond > 0 && *value > endValue) || (incrementPerSecond < 0 && *value < endValue)) {
        *value = startValue;
        triggered = true;
    }else{
        triggered = false;
    }
}