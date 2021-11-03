#include "keyboard.h"


/**
 * @brief Update all buttons of the keyboard.
 *
 * @param window GLFWWIndow
 * @param keys Keys to be checked
 */
void Keyboard::update(std::unordered_map<int, std::pair<int, bool>>keys) {
    for (auto key = keys.begin(); key != keys.end(); key++) {
        key->second.second = glfwGetMouseButton(window, key->second.first);
    }
}

