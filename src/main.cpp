#include <iostream>
#include "enschin/screen/window.h"
#include "scenes/game_scene.h"
#include "my_game.h"


int main()
{

    MyGame* myGame = new MyGame("Enschin", {600.0f, 600.0f}, 0);
    GameScene* myScene = new GameScene(*myGame);
    myGame->start(*myScene);

    return 0;
}