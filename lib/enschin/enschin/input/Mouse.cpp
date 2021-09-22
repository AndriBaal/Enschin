#include "Mouse.h"

Vector2 Mouse::mousePos = Vector2();

bool Mouse::buttons[] = {};

void Mouse::updateCursor(GLFWwindow* window, double xpos, double ypos)
{
	double x, y = 0;
	glfwGetCursorPos(window, &x, &y);
	Mouse::mousePos = Vector2{ (float)x, (float)y };
}

void Mouse::updateButtons(GLFWwindow* window, int button, int action, int mods)
{
	buttons[button] = action;
}

bool Mouse::isButtonPressed(int button)
{
	return buttons[button];
}