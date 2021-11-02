#include <iostream>
#include "enschin/screen/window.h"
#include "scenes/game_scene.h"
#include "my_game.h"


int main()
{
    MyGame myGame = MyGame("Enschin", {600.0f, 600.0f}, 0);
    std::cout << sizeof(myGame) << std::endl;
    return 0;
}