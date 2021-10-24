#include <enschin/Window.h>
#include <iostream>
#include "scenes/GameScene.h"
#include <MyGame.h>


int main()
{

    MyGame* myGame = new MyGame();
    Window* window = new Window("Enschin", {770.0f, 1280.0f}, 0);
    GameScene* myScene = new GameScene();
    myGame->start(window, myScene);

    return 0;
}