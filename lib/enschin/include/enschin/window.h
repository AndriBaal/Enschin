#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include "../../deps/stb/stb_image.h"
#include "vec2i.h"
#include "color.h"
#include "renderer.h"

/**
 * @brief GLFWWindow wrapper
 */
class Window {
private:
    Vec2i windowSize;
    bool fullScreen;
    bool vSync = true;
    GLFWwindow *window;
public:
    Window() = default;
    Window(std::string title, Vec2i size, bool fullscreen);

    bool update();
    Vec2i getSize() const { return windowSize; }
    GLFWwindow *getGlfw() const { return window; }
    void setSize(Vec2i v);
    void setFullScreen(bool fullscreen);
    void setTitle(std::string title);
    void setClearColor(Color newColor);
    void setVSync(bool vSync);
    void setIcon(const char *filePath);
    void setAntialiasing(bool state) { if (state)glEnable(GL_MULTISAMPLE); else glDisable(GL_MULTISAMPLE); }
};