#include <game/my_game.h>

int main(void) {
    MyGame myGame = MyGame("Enschin", {800, 600}, 0);
    myGame.init();
    return 0;
}