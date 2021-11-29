#include <game/my_game.h>

void MyGame::start(const GameContext& ctx) {
    window.setIcon("./textures/bird.jpg");
    res = new Ressources("./ressources/ulul.json");
    input = new Input("./settings/input/events/events.json");
    myScene = new GameScene(res, input, ctx);
    currentScene = myScene;
}

void MyGame::loop(const GameContext& gtx) {
	//set the current Scene here
}

void MyGame::free() {
    Game::free();
    delete res;
    delete input;
    delete currentScene;
}