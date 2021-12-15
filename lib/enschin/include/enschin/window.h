#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include "../../deps/stb/stb_image.h"
#include "vec2f.h"
#include "color.h"
#include "renderer.h"

/**
 * @brief GLFWWindow wrapper
 */
class Window {
private:
    Vec2f windowSize;
    bool fullScreen;
    bool vSync = true;
    GLFWwindow *window;
public:
    Window() = default;

    Window(std::string title, Vec2f size, bool fullscreen);

    bool update();

    Vec2f getSize() { return windowSize; }

    GLFWwindow *getGlfw() { return window; }

    void setSize(Vec2f v);

    void setFullScreen(bool fullscreen);

    void setTitle(std::string title);

    void setClearColor(Color newColor);

    void setVSync(bool vSync);

    void setIcon(const char *filePath);

    void setAntialiasing(bool state) { if (state)glEnable(GL_MULTISAMPLE); else glDisable(GL_MULTISAMPLE); }
};