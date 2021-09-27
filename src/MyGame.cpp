#include "MyGame.h"

void MyGame::update()
{
		currentScene->update();
		currentScene->render();
}