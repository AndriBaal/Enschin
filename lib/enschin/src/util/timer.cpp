#include <enschin/timer.h>

bool Timer::activeAll = true;

void Timer::startAll(){ activeAll=true; }
void Timer::stopAll(){ activeAll=false; }
bool Timer::isActiveAll() { return activeAll; }

Timer::Timer(float startValue, float endValue, float incrementPerSecond, bool active)
    : startValue(startValue), endValue(endValue), incrementPerSecond(incrementPerSecond), active(active) {
    value = startValue;
}

void Timer::update(float deltaTime) {
    float increment = deltaTime * incrementPerSecond;
    value += increment;
    totalValue += increment;
    if ((incrementPerSecond > 0 && value > endValue) || (incrementPerSecond < 0 && value < endValue)) {
        value = startValue;
        triggered = true;
    }else{
        triggered = false;
    }
}

bool Timer::take() {
    if ((incrementPerSecond > 0 && totalValue > endValue) || (incrementPerSecond < 0 && totalValue < endValue)) {
        totalValue = startValue;
        return true;
    }else{
        return false;
    }
}