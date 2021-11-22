#include <enschin/window.h>

/**
 * @brief Create and initialize the window,
 * 
 * @param windowTitle Title of the window
 * @param windowSize Size of the window
 * @param fullScreen Set fullscreen
 */
Window::Window(std::string windowTitle, Vec2 windowSize, bool fullScreen) {
    if (!glfwInit()) exit(0);
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_AUTO_ICONIFY, GLFW_FALSE);

    /*glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);*/
    //glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    glfwWindowHint(GLFW_SAMPLES, 4);

    if (fullScreen) {
        window = glfwCreateWindow(windowSize.x, windowSize.y, &windowTitle[0], glfwGetPrimaryMonitor(), NULL);
    } else {
        window = glfwCreateWindow(windowSize.x, windowSize.y, &windowTitle[0], NULL, NULL);
    }

    if (!window) {
        glfwTerminate();
        exit(0);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    if (glewInit() != GLEW_OK) exit(0);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glEnable(GL_TRIANGLES);
    glEnable(GL_MULTISAMPLE);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    int w, h = 0;
    glfwGetWindowSize(window, &w, &h);
    windowSize.x = w;
    windowSize.y = h;
    this->windowSize = windowSize;
    this->fullScreen = fullScreen;
}

/**
 * @brief Updates the window and checks if the size has changed
 * 
 * @return true Size has changed
 * @return false Size hasn't changed
 */
bool Window::update() {
    int w, h;
    glfwGetWindowSize(window, &w, &h);
    if (w != windowSize.x || h != windowSize.y) {
        glViewport(0, 0, w, h);
        windowSize = {float(w), float(h)};
        return true;
    }
    return false;
}

/**
 * @brief Set size of the window.
 * 
 * @param newDim New size
 */
void Window::setSize(Vec2 newDim) {
    windowSize = newDim;
    glfwSetWindowSize(window, newDim.x, newDim.y);
}

/**
 * @brief Set the title of the window.
 * 
 * @param title New title
 */
void Window::setTitle(std::string title) {
    glfwSetWindowTitle(window, &title[0]);
}

/**
 * @brief Set the fullscrenn mode
 * 
 * @param fullScreen state
 */
void Window::setFullScreen(bool fullScreen) {
    if (this->fullScreen == fullScreen) return;

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    if (fullScreen) {
        glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
        std::cout << "fullscreen activated" << std::endl;
    } else {
        glfwSetWindowMonitor(window, nullptr, 0, 45, mode->width, mode->height, mode->refreshRate);
    }
    setVSync(vSync);
    this->fullScreen = fullScreen;
}

void Window::setClearColor(Color newColor) {
    glClearColor(newColor.r, newColor.g, newColor.b, newColor.a);
}

/**
 * @brief Set VSync
 * 
 * @param vSync State
 */
void Window::setVSync(bool vSync) {
    if (vSync) {
        glfwSwapInterval(1);
    } else {
        glfwSwapInterval(0);
    }
    this->vSync = vSync;
}

/**
 * Set the display icon for the window
 * @param filePath Filepath of the image
 */
void Window::setIcon(const char *filePath) {
    GLFWimage images[1];
    images[0].pixels = stbi_load(filePath, &images[0].width, &images[0].height, 0, 4); //rgba channels
    glfwSetWindowIcon(window, 1, images);
    stbi_image_free(images[0].pixels);
}