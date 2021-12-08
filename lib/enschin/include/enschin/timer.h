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
    float totalValue;
public:
    Timer() = default;

    Timer(float startValue, float endValue, float incrementPerSecond = 1.0f, bool active = true);

    void update(float deltaTime);

    static void startAll();

    static void stopAll();

    static bool isActiveAll();

    void start() { active = true; }

    void stop() { active = false; }

    bool take();

    bool isActive() const { return active; }

    bool isTriggered() const { return triggered; }

    float getValue() const { return value; }
};