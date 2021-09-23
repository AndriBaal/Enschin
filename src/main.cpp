#include <enschin/Window.h>
#include <iostream>
#include "scenes/GameScene.h"
#include "MyGame.h"


int main(void)
{
    if (!glewInit()) exit(0);
    Window* window = new Window("sddgffk", { 480, 480 }, false);
    MyGame* mG = new MyGame();
    GameScene* gS = new GameScene();
    mG->start(window, gS);
    window->setClearColor(Color{ 0, 1, 1, 1 });
}