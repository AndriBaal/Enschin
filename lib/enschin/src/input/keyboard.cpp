#include <enschin/keyboard.h>


/**
 * @brief Update all buttons of the keyboard.
 *
 * @param window GLFWwindow
 * @param keys Keys to be checked
 */
void Keyboard::update(GLFWwindow* window) {
    for (auto i = keys.begin(); i != keys.end(); i++) {
        *i->second = glfwGetKey(window, i->first);
    }
}

