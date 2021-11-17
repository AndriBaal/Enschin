#include <enschin/game.h>


Game::Game(std::string gameName, Dim2 windowSize, bool fullscreen) {
	window = Window(gameName, windowSize, fullscreen);
}

/**
 * @brief Start the game
 * 
 * @param window Window*
 * @param startScene First appearing scene
 * @param currentRessources First used ressource_bundles for the scene
 */
void Game::init() {
    Renderer::initShaderPrograms();
    GLFWwindow* glfw = window.getGlfw();

    start();
	while (!glfwWindowShouldClose(glfw)) {
        glClear(GL_COLOR_BUFFER_BIT);

		if (window.update()) {
			currentScene->getRenderer().resetProjection(window.getSize());
		}

		secondTime = glfwGetTime();
		deltaTime = float(secondTime - firstTime);
        firstTime = glfwGetTime();
        totalTime = (float) firstTime;

        glfwPollEvents();
		loop();
        currentScene->updateTimers(deltaTime);
        currentScene->updateInput(glfw);
        currentScene->update();
        currentScene->render();
		fps++;
		if (glfwGetTime() > lastTime+1) {
			std::cout << fps << std::endl;
			lastTime = glfwGetTime();
			fps = 0;
		}
		running = true;
        glfwSwapBuffers(glfw);
    }
	running = false;
    glfwDestroyWindow(glfw);
    glfwTerminate();
    free();
}