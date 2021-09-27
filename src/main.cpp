#include <enschin/Window.h>
#include <iostream>
#include "scenes/GameScene.h"
#include <MyGame.h>


int main(void)
{
    MyGame* myGame = new MyGame();
    GameScene* myScene = new GameScene();
    MyRenderer* myRenderer = new Renderer();
    myGame->start(myScene);
}