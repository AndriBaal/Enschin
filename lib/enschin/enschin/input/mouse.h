#pragma once
#include <iostream>
#include <unordered_map>
#include <GLFW/glfw3.h>
#include "enschin/math/vec2.h"

/**
 * @brief Mouse class that handles input
 */
class Mouse {
private:
	Vec2 translateMousePosition(float units, double mouseX, double mouseY, int windowW, int windowH);
public:
    Mouse() = default;
	void updateCursor(GLFWwindow* window, float units, Vec2& cursorPos);
};

