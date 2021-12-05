#include <enschin/keyboard.h>


/**
 * @brief Update all buttons of the keyboard.
 *
 * @param window GLFWwindow
 * @param keys Keys to be checked
 */
void Keyboard::update(GLFWwindow* window) {
    for (auto & mapping : mappings) {
        if (mapping.mappingType == KEY)
            *mapping.event = glfwGetKey(window, mapping.key);
        else
            *mapping.event = glfwGetMouseButton(window, mapping.key);
    }
}

