#include "my_game.h"


void MyGame::start() {
    window.setIcon("./textures/bird.jpg");
    Ressources* r = new Ressources();
    RessourceLoader::loadGameRessources(*r);
    RessourceLoader::loadGameInput(getInput());
    GameScene* myScene = new GameScene(*this);
    currentScene = myScene;
    currentRessources = r;
}

void MyGame::loop() {
	//set the current Scene here
}

void MyGame::free() {
    //Cleanup when closing
}