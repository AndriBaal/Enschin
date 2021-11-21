#pragma once

class Timer {
private:
    static bool activeAll;
    bool triggered;
    bool active;
    float startValue;
    float endValue;
    float incrementPerSecond;
    float value;
public:
    Timer() = default;
    Timer(float startValue, float endValue, float incrementPerSecond, bool active=false);
    void update(float deltaTime);
    static void startAll();
    static void stopAll();
    static bool isActiveAll();
    void start(){ active=true; }
    void stop(){ active=false; }
    bool isActive() { return active; }
    bool isTriggered(){ return triggered; }
    float getValue(){ return value; }
};