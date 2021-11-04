#include "my_game.h"


void MyGame::start() {
    GameScene myScene = GameScene(*this);
    Ressources r = Ressources();
    RessourceLoader::loadGameRessources(r);
    currentScene = &myScene;
    currentRessources = &r;
    Game::start();
}

void MyGame::loop() {
	//set the current Scene here

}