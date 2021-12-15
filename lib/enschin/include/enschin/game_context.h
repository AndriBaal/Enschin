#pragma once

#include <GLFW/glfw3.h>
#include "vec2f.h"

struct GameContext {
    GLFWwindow *window;
    Vec2f windowSize;
    const float deltaTime;
    const float totalTime;
};