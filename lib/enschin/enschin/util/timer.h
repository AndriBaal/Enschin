#pragma once
#include "enschin/screen/scene.h"

class Scene;
class Timer {
private:
    static bool activeAll;
    bool triggered;
    bool active;
    float startValue;
    float endValue;
    float incrementPerSecond;
    float value;
    Scene* scene;
public:
    Timer() = default;
    Timer(Scene* scene, float startValue, float endValue, float incrementPerSecond, bool active=false);
    void update(float deltaTime);
    static void startAll();
    static void stopAll();
    void start(){ active=true; }
    void stop(){ active=false; }
    bool isTriggered(){ return triggered; }
    static bool isActiveAll();
    bool isActive() { return active; }
};