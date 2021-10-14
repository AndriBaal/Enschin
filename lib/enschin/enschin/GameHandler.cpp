#include "GameHandler.h"



void GameHandler::start(Window* window, Scene* currentScene)
{
	this->currentScene = currentScene;
	this->window = window;
	Renderer::init(window->getSize());

	GLFWwindow* glfw = window->getGlfw();

	while (!glfwWindowShouldClose(glfw))
    {
        glClear(GL_COLOR_BUFFER_BIT);
    
		secondTime = getNanos();
		deltaTime = (float)secondTime - firstTime;
		deltaTime /= 1000000000.0f;
		firstTime = getNanos();

		process();
		
		fps++;
		if (getNanos() > lastTime + 1000000000) 
		{
			std::cout << fps << std::endl;
			lastTime = getNanos();
			fps = 0;
		}

        glfwSwapBuffers(window->getGlfw());
        glfwPollEvents();
    }
    glfwTerminate();
	exit(0);
}


long long GameHandler::getNanos()
{
	return std::chrono::time_point_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now()).time_since_epoch().count();
}
