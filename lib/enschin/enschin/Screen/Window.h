#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "enschin/math/Dim.h"
#include "enschin/math/Vec2.h"
#include "enschin/graphics/effects/Color.hpp"
#include "enschin/graphics/Renderer.h"
#include "enschin/input/Keyboard.h"
#include "enschin/input/Mouse.h"

class Window {
private:
	Dim windowSize;
	bool fullScreen;
	bool vSync = true;
	std::string windowTitle;
	GLFWwindow* window;
public:
	Window(std::string title, Dim size, bool fullscreen);
	static void windowSizeCallback(GLFWwindow* window, int width, int height);
	Dim getSize() { return windowSize; }
	GLFWwindow* getGlfw() { return window; }
	void setSize(Dim& v);
	void setFullScreen(bool fullscreen);
	void setTitle(std::string title);
	void setClearColor(Color newColor);
	void setVSync(bool vSync);
};