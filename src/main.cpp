#include <enschin/screen/Window.h>
#include <iostream>
#include "scenes/GameScene.h"
#include <MyGame.h>


int main()
{

    MyGame* myGame = new MyGame("Enschin", {600.0f, 600.0f}, 0);
    GameScene* myScene = new GameScene(*myGame);
    myGame->start(*myScene);

    return 0;
}