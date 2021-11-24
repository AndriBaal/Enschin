#include <enschin/keyboard.h>


/**
 * @brief Update all buttons of the keyboard.
 *
 * @param window GLFWwindow
 * @param keys Keys to be checked
 */
void Keyboard::update(GLFWwindow* window) {
    for (auto i = mappings.begin(); i != mappings.end(); i++) {
        *i->event = glfwGetKey(window, i->key);
    }
}

