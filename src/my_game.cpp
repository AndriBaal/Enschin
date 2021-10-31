#include "my_game.h"

MyGame::MyGame(std::string gameName, Dim2 windowSize, bool fullscreen):Game(gameName, windowSize, fullscreen) {
    GameScene myScene = GameScene(*this);
	GameRessources myRessources = GameRessources();
    start(myScene, myRessources);
}

void MyGame::loop() {
	//set the current Scene here
}