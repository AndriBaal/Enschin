#include <game/my_game.h>

void MyGame::start(const GContext& ctx) {
    window.setIcon("./textures/bird.jpg");
    myScene = new GameScene(ctx);
    currentScene = myScene;
}

void MyGame::loop(const GContext& gtx) {
	//set the current Scene here
}

void MyGame::free() {
    Game::free();
    delete currentScene;
}