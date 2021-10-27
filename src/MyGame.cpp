#include "MyGame.h"

MyGame::MyGame():Game() {

}

void MyGame::loop() {
	currentScene->update();
	currentScene->render();
}