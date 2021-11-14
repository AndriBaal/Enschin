#include <iostream>
#include "my_game.h"

int main() {
    MyGame myGame = MyGame("Enschin", {500.0f, 500.0f}, 0);
    myGame.init();
    myGame.free();
    return 0;
}