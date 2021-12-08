#pragma once

#include <GLFW/glfw3.h>
#include <unordered_map>
#include <utility>
#include <vector>
#include "mapping.h"

/**
 * @brief Keyboard class that handles keyboard inputs
 */
class Keyboard {
private:
    std::vector<Mapping> mappings;
public:
    Keyboard() = default;

    Keyboard(std::vector<Mapping> mappings) : mappings(std::move(mappings)) {

    }

    void update(GLFWwindow *window);
};