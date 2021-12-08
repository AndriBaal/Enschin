#pragma once

#include <GLFW/glfw3.h>
#include "vec2.h"

struct GameContext {
    GLFWwindow *window;
    Vec2 windowSize;
    const float deltaTime;
    const float totalTime;
};