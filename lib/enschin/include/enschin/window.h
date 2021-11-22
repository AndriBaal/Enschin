#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "../../deps/stb/stb_image.h"
#include "vec2.h"
#include "color.h"
#include "renderer.h"

/**
 * @brief GLFWWindow wrapper
 */
class Window {
private:
    Vec2 windowSize;
	bool fullScreen;
	bool vSync = true;
	GLFWwindow* window;
public:
    Window() = default;
	Window(std::string title, Vec2 size, bool fullscreen);
	bool update();
	Vec2 getSize() { return windowSize; }
	GLFWwindow* getGlfw() { return window; }
	void setSize(Vec2 v);
	void setFullScreen(bool fullscreen);
	void setTitle(std::string title);
	void setClearColor(Color newColor);
	void setVSync(bool vSync);
    void setIcon(const char *filePath);
};