#include "my_game.h"


void MyGame::start() {
    window.setIcon("./textures/bird.jpg");
    GameScene* myScene = new GameScene(*this);
    currentScene = myScene;
}

void MyGame::loop() {
	//set the current Scene here
}

void MyGame::free() {
    //Cleanup when closing
    delete myScene;
}