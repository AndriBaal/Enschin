#include "GameHandler.h"



void GameHandler::start(Window* window, Scene* currentScene)
{
	//SceneHandler::window = window;
	this->currentScene = NULL;
	this->window = NULL;
	firstTime = 0;
	secondTime = 0;
	lastTime = 0;
	deltaTime = 0;
	fps = 0;
	this->window = window;
	Renderer::init(window);
	this->currentScene = currentScene;
}

void GameHandler::updateCurrentScene()
{
	while (!glfwWindowShouldClose(window->getGlfw()))
    {
        glClear(GL_COLOR_BUFFER_BIT);
    
		secondTime = getNanos();
		deltaTime = (float)secondTime - firstTime;
		deltaTime /= 1000000000.0f;
		firstTime = getNanos();

		currentScene->update();
		currentScene->render();

		
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
