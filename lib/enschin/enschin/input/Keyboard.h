#pragma once

#include <GLFW/glfw3.h>

class Keyboard {
private:
	static bool keys[255];

public:
	static void update(GLFWwindow* window, int key, int scancode, int action, int mods);
	static bool isKeyPressed(int key);
};