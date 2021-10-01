#include <enschin/Window.h>
#include <iostream>
#include "scenes/GameScene.h"
#include <MyGame.h>


int main()
{
    MyGame* myGame = new MyGame();
    Window* window = new Window("Enschin", { 1920, 1080 }, 0);
    GameScene* myScene = new GameScene();
    MyRenderer* myRenderer = new MyRenderer();
    myGame->start(window, myScene, myRenderer);

    return 0;
}