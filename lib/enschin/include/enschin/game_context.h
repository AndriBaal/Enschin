#pragma once

#include <GLFW/glfw3.h>
#include "vec2f.h"

struct GameContext {
    const Window& window;
    const float deltaTime;
    const float totalTime;
};