#include "keyboard.h"

bool Keyboard::keys[] = {};

/**
 * @brief 
 * 
 * @param key 
 * @return true 
 * @return false 
 */

/**
 * @brief Check if a certain key is pressed
 * 
 * @param key K
 * @return true Key is pressed
 * @return false KEy isnt pressed
 */
bool Keyboard::isKeyPressed(int key) {
	return keys[key];
}

/**
 * @brief KeyEvent that gets called when e key gets pressed
 * 
 * @param window GLFW window pointer
 * @param key Keycode
 * @param scancode ..
 * @param action Action of the key (press, lift)
 * @param mods ..
 */
void Keyboard::update(GLFWwindow* window, int key, int scancode, int action, int mods) {
	keys[key] = action;
}

