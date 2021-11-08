#include "timer.h"

bool Timer::activeAll = false;

void Timer::startAll(){ activeAll=1; }
void Timer::stopAll(){ activeAll=0; }
bool Timer::isActiveAll() { return activeAll; }

void Timer::update(float deltaTime) {
    if (*countableValue) {

    }
}