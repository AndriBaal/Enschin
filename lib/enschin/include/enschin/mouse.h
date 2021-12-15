#pragma once

#include <iostream>
#include <unordered_map>
#include <GLFW/glfw3.h>
#include "vec2f.h"

/**
 * @brief Mouse class that handles input
 */
class Mouse {
private:
    Vec2f translateMousePosition(float units, double mouseX, double mouseY, int windowW, int windowH);

public:
    Mouse() = default;

    void updateCursor(GLFWwindow *window, float units, Vec2f &cursorPos);
};

