#include "game.h"


Game::Game(std::string gameName, Dim2 windowSize, bool fullscreen) {
	window = new Window(gameName, windowSize, fullscreen);
}

/**
 * @brief Start the game
 * 
 * @param window Window*
 * @param startScene First appearing scene
 * @param currentRessources First used ressources for the scene
 */
void Game::start(Scene& startScene, Ressources& startRessources) {
	this->currentScene = &startScene;
	this->currentRessources = &startRessources;
	Renderer::initShaderPrograms();
	
	GLFWwindow* glfw = window->getGlfw();

	while (!glfwWindowShouldClose(glfw)) {
        glClear(GL_COLOR_BUFFER_BIT);

		if (window->update()) {
			currentScene->getRenderer().resetProjection(window->getSize());
		}
    
		secondTime = getNanos();
		deltaTime = (float)secondTime - firstTime;
		deltaTime /= 1000000000.0f;
		firstTime = getNanos();

        glfwPollEvents();
		loop();

		
		fps++;
		if (getNanos() > lastTime + 1000000000) {
			//std::cout << fps << std::endl;
			lastTime = getNanos();
			fps = 0;
		}
		running = true;
        glfwSwapBuffers(glfw);
    }
	running = false;
    glfwTerminate();
}

/**
 * @brief Get the current nano second runtime;
 * 
 * @return long long Runtime in nano seconds
 */
long long Game::getNanos() {
	return std::chrono::time_point_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now()).time_since_epoch().count();
}
