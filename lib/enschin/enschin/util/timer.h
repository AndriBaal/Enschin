#pragma once
#include "enschin/screen/scene.h"

class Scene;
class Timer {
private:
    static bool activeAll;
    bool active;
    float delay;
    float minValue;
    float maxValue;
    float increment;
    float* value;
    Scene* scene;
public:
    Timer(Scene* scene, float delay, float minValue, float maxValue, float increment, float* value, bool active=false)
     : scene(scene), delay(delay), minValue(minValue), maxValue(maxValue), increment(increment), value(value), active(active){}
    void update(float deltaTime);
    static void startAll();
    static void stopAll();
    void start(){ active=1; };
    void stop(){ active=0; };
    static bool isActiveAll();
    bool isActive() const { return active; }
};