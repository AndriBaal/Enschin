#include "mouse.h"

/**
 * @brief Updates the position of the Cursor
 * @param units Units
 * @param cursorPos Vec2 to write into
 */
void Mouse::updateCursor(GLFWwindow* window, float units, Vec2& cursorPos) {
    double x, y;
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    glfwGetCursorPos(window, &x, &y);
    cursorPos = translateMousePosition(units, x, y, width, height);

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
Vec2 Mouse::translateMousePosition(float units, double mouseX, double mouseY, int windowW, int windowH) {
	return Vec2(
		(float(mouseX)/windowW*2.0f*units-units) * (windowW / float(windowH)),
		-float(mouseY)/windowH*2.0f*units+units
	);
}