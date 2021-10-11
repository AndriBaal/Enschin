#include "MyGame.h"

MyGame::MyGame():GameHandler(){

}

void MyGame::process()
{
	currentScene->update();
	currentScene->render(*renderer);
}