#include "timer.h"

bool Timer::activeAll = true;

void Timer::startAll(){ activeAll=1; }
void Timer::stopAll(){ activeAll=0; }
bool Timer::isActiveAll() { return activeAll; }

Timer::Timer(Scene *scene, float minValue, float maxValue, float incrementPerSecond, float *value, bool active)
    : scene(scene), minValue(minValue), maxValue(maxValue), incrementPerSecond(incrementPerSecond), value(value), active(active) {
    scene->addTimer(this);
    *value = minValue;
}

void Timer::update(float deltaTime) {
    *value += deltaTime * incrementPerSecond;
    if (*value > maxValue) {
        *value = minValue;
        triggered = true;
        std::cout << maxValue << std::endl;
    }else{
        triggered = false;
    }
}