#include <iostream>
#include "my_game.h"

int main() {
    MyGame myGame = MyGame("Enschin", {600.0f, 600.0f}, 0);
    myGame.start();
    return 0;
}