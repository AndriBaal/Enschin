#include "Window.h"

Window::Window(std::string windowTitle, Dimension windowSize, bool fullScreen)
{
    if (!glfwInit()) exit(0);
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    /*glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);*/
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    if (fullScreen) 
    {
        window = glfwCreateWindow(windowSize.w, windowSize.h, &windowTitle[0], glfwGetPrimaryMonitor(), NULL);
    }
    else
    {
        window = glfwCreateWindow(windowSize.w, windowSize.h, &windowTitle[0], NULL, NULL);
    }

    if (!window)
    {
        glfwTerminate();
        exit(0);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    if (glewInit() != GLEW_OK) exit(0);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glEnable(GL_TRIANGLES);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    this->windowSize = windowSize;
    this->fullScreen = fullScreen;
    this->windowTitle = windowTitle;
    
    glfwSetCursorPosCallback(window, Mouse::updateCursor);
    glfwSetMouseButtonCallback(window, Mouse::updateButtons);
    glfwSetKeyCallback(window, Keyboard::update);
    // glfwSetWindowSizeCallback(window, Window::windowSizeCallback);
}

GLFWwindowsizefun Window::windowSizeCallback(GLFWwindow* window, int width, int height)
{

}

Dimension Window::getSize()
{
    return windowSize;
}

void Window::setSize(Dimension& newDim)
{
    windowSize = newDim;
    glfwSetWindowSize(window, newDim.w, newDim.h);
    Renderer::resetProjection(windowSize);
}

void Window::setTitle(std::string title)
{
    glfwSetWindowTitle(window, &title[0]);
}

void Window::setFullScreen(bool fullScreen)
{
    if (this->fullScreen == fullScreen) { return;  }

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    if (fullScreen)
    {
        glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
        std::cout << "fullscreen activated" << std::endl;
    }
    else
    {
        glfwSetWindowMonitor(window, nullptr, 0, 45, mode->width, mode->height, mode->refreshRate);
    }
    setVSync(vSync);
    this->fullScreen = fullScreen;
}

void Window::setClearColor(Color newColor)
{
    glClearColor(newColor.r, newColor.g, newColor.b, newColor.a);
}

void Window::setVSync(bool vSync)
{
    if (vSync)
    {
        glfwSwapInterval(1);
    }
    else
    {
        glfwSwapInterval(0);
    }

    this->vSync = vSync;
}

GLFWwindow* Window::getGlfw()
{
    return this->window;
}

