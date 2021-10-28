#pragma once
#include "enschin/math/vec2.h"
#include <iostream>
#include <GLFW/glfw3.h>

/**
 * @brief Mouse class that handles input
 */
class Mouse {
private:
	static bool buttons[8];
	static Vec2 mousePos;
	static float units;
	static Vec2 translateMousePosition(double mouseX, double mouseY, int windowW, int windowH);

public:
	static void updateButtons(GLFWwindow* window, int button, int action, int mods);
	static void updateCursor(GLFWwindow* window, double xpos, double ypos);
	static bool isButtonPressed(int button);
	static Vec2 getMousePos() { return mousePos; }

	static void setUnits(float units){ Mouse::units=units; }
};

