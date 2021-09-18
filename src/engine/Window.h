#pragma once
//#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include "math/Dimension.h"
#include "math/Vectors.h"
#include "graphics/Color.h"
//#include "GameHandler.h"
#include "input/Keyboard.h"
#include "input/Mouse.h"

class Window
{
private:
	Dimension windowSize;
	bool fullScreen;
	bool vSync = true;
	std::string windowTitle;
	GLFWwindow* window;
public:
	Window(std::string title, const Dimension& size, bool fullscreen);
	Dimension getSize();
	void setSize(Dimension& v);
	void setFullScreen(bool fullscreen);
	void setTitle(std::string title);
	void setClearColor(Color newColor);
	void setVSync(bool vSync);
	void startApp();

};