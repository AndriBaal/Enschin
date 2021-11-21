#include <iostream>
#include <game/my_game.h>

int main() {
    MyGame myGame = MyGame("Enschin", {800.0f, 600.0f}, 0);
    myGame.init();
    return 0;
}