#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "math/Dim.h"
#include "math/Vec2.h"
#include "graphics/Color.hpp"
#include "graphics/Renderer.h"
#include "GameHandler.h"
#include "input/Keyboard.h"
#include "input/Mouse.h"

class Window
{
private:
	Dim windowSize;
	bool fullScreen;
	bool vSync = true;
	std::string windowTitle;
	GLFWwindow* window;
public:
	Window(std::string title, Dim size, bool fullscreen);
	static void windowSizeCallback(GLFWwindow* window, int width, int height);
	Dim getSize();
	void setSize(Dim& v);
	void setFullScreen(bool fullscreen);
	void setTitle(std::string title);
	void setClearColor(Color newColor);
	void setVSync(bool vSync);
	GLFWwindow* getGlfw();
};