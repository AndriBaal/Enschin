#include "Mouse.h"

Vector2 Mouse::mousePos = Vector2();

bool Mouse::buttons[] = {};
float Mouse::units = 0;

void Mouse::updateCursor(GLFWwindow* window, double xpos, double ypos)
{
	double x, y = 0;
	glfwGetCursorPos(window, &x, &y);
	int windowX, windowY = 0;
	glfwGetWindowPos(window, &windowX, &windowY); 
	Mouse::mousePos = translateMousePosition(x, y, windowX, windowY);
}

void Mouse::updateButtons(GLFWwindow* window, int button, int action, int mods)
{
	buttons[button] = action;
}

bool Mouse::isButtonPressed(int button)
{
	return buttons[button];
}

Vector2 Mouse::translateMousePosition(double x, double y, int windowX, int windowY)
{
	float ratio = windowX / windowY;
	float newX = 25.0f;
	float newY = -float(y)/windowY*2*units/4.0f+units;
	return Vector2(newX, newY);
}
