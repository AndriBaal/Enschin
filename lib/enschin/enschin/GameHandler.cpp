#include "GameHandler.h"

Scene* GameHandler::currentScene = NULL;
Window* GameHandler::window = NULL;
long long GameHandler::firstTime = 0;
long long GameHandler::secondTime = 0;
long long GameHandler::lastTime = 0;
float GameHandler::deltaTime = 0;
float GameHandler::fps = 0;

void GameHandler::start(Window* window, Scene& currentScene)
{
	//SceneHandler::window = window;
	this->window = window;
	Renderer::init(window);
	currentScene = new GameScene();
}

void GameHandler::updateCurrentScene()
{
	while (!glfwWindowShouldClose(window))
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

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
	exit(0);
}

long long GameHandler::getNanos()
{
	return std::chrono::time_point_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now()).time_since_epoch().count();
}
