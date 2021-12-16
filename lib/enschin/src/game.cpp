#include <enschin/game.h>


Game::Game(std::string gameName, Vec2i windowSize, bool fullscreen) : gameName(gameName){
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

    start({
                  window,
                  deltaTime,
                  totalTime
          });
	while (!glfwWindowShouldClose(glfw)) {
        glClear(GL_COLOR_BUFFER_BIT);

		if (window.update()) {
			currentScene->getCamera().setFov(window.getSize(), currentScene->getCamera().getFov());
		}

		secondTime = glfwGetTime();
		deltaTime = float(secondTime - firstTime);
        firstTime = glfwGetTime();
        totalTime = (float) firstTime;

        const GameContext gameContext = {
                window,
                deltaTime,
                totalTime
        };

        glfwPollEvents();
		loop(gameContext);
        currentScene->update(gameContext);
        currentScene->render(gameContext);
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

void Game::free() {
    Renderer::free();
}