#include "Game.h"

/**
 * @brief Start the game
 * 
 * @param window Window*
 * @param currentScene First appearing scene
 */
void Game::start(Window* window, Scene* currentScene) {
	this->currentScene = currentScene;
	this->window = window;
	Renderer::init(window->getSize(), 1.0f);

	GLFWwindow* glfw = window->getGlfw();

	while (!glfwWindowShouldClose(glfw)) {
        glClear(GL_COLOR_BUFFER_BIT);
    
		secondTime = getNanos();
		deltaTime = (float)secondTime - firstTime;
		deltaTime /= 1000000000.0f;
		firstTime = getNanos();

		Renderer::resetMatrix();
        glfwPollEvents();
		loop();
		
		fps++;
		if (getNanos() > lastTime + 1000000000) {
			//std::cout << fps << std::endl;
			lastTime = getNanos();
			fps = 0;
		}


        glfwSwapBuffers(glfw);
    }
    glfwTerminate();
	exit(0);
}

/**
 * @brief Get the current nano second runtime;
 * 
 * @return long long Runtime in nano seconds
 */
long long Game::getNanos() {
	return std::chrono::time_point_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now()).time_since_epoch().count();
}
