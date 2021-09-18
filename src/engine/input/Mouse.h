#pragma once
#include "../math/Vectors.h"
#include "../Window.h"
#include <iostream>
#include "GLFW/glfw3.h"

class Mouse
{
private:
	static bool buttons[8];
	static Vector2 mousePos;

public:
	static void updateButtons(GLFWwindow* window, int button, int action, int mods);
	static void updateCursor(GLFWwindow* window, double xpos, double ypos);
	static bool isButtonPressed(int button);
	static Vector2 getMousePos() { return mousePos; }
};

