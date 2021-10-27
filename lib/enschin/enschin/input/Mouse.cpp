#include "Mouse.h"

Vec2 Mouse::mousePos = Vec2();

bool Mouse::buttons[] = {};
float Mouse::units = 0;

/**
 * @brief Cursor callback that gets called when the cursor moves
 * 
 * @param window GLFWWindow pointer
 * @param xpos mouse x
 * @param ypos mouse y
 */
void Mouse::updateCursor(GLFWwindow* window, double xpos, double ypos) {
	int windowW, windowH = 0;
	glfwGetWindowSize(window, &windowW, &windowH); 
	Mouse::mousePos = translateMousePosition(xpos, ypos, windowW, windowH);
}

/**
 * @brief Update the mouse buttons
 * 
 * @param window 
 * @param button 
 * @param action 
 * @param mods 
 */
void Mouse::updateButtons(GLFWwindow* window, int button, int action, int mods) {
	buttons[button] = action;
}

/**
 * @brief Check if a mouse button is pressed or not
 * 
 * @param button 
 * @return true Mouse button is pressed
 * @return false Mouse button isn't pressed
 */
bool Mouse::isButtonPressed(int button) {
	return buttons[button];
}

/**
 * @brief Translate the Mouse coordinates from the window coordinates to
 * matching coordinates in the matrix
 * 
 * @param mouseX mouse x
 * @param mouseY mous y
 * @param windowW window width
 * @param windowH window height
 * @return Vec2 Returns the translated mouse position
 */
Vec2 Mouse::translateMousePosition(double mouseX, double mouseY, int windowW, int windowH) {
	return Vec2(
		(float(mouseX)/windowW*2.0f*units-units) * (windowW / float(windowH)),
		-float(mouseY)/windowH*2.0f*units+units
	);
}