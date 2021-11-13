#include <iostream>
#include "my_game.h"

int main() {
    MyGame myGame = MyGame("Enschin", {1920.0f, 1080.0f}, 1);
    myGame.init();
    return 0;
}