#pragma once

#include <GLFW/glfw3.h>
#include <unordered_map>

/**
 * @brief Keyboard class that handles keyboard inputs
 */
class Keyboard {
private:
    GLFWwindow* window;
public:
    Keyboard() = default;
    Keyboard(GLFWwindow* window) : window(window){}
    void update(std::unordered_map<int, std::pair<int, bool>>keys);
};