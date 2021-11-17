#pragma once

#include <GLFW/glfw3.h>
#include <unordered_map>
#include <vector>

/**
 * @brief Keyboard class that handles keyboard inputs
 */
class Keyboard {
private:
    std::vector<std::pair<int, bool*>> keys;
public:
    Keyboard() = default;
    Keyboard(std::vector<std::pair<int, bool*>> keys) : keys(keys){

    }
    void update(GLFWwindow* window);
};