#include "MyGame.h"

MyGame::MyGame():Game() {

}

void MyGame::process() {
	currentScene->update();
	currentScene->render();
}