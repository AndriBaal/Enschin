#include "Keyboard.h"

bool Keyboard::keys[] = {};

bool Keyboard::isKeyPressed(int key)
{
	return keys[key];
}

void Keyboard::update(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	keys[key] = action;
}

