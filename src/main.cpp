#include <iostream>
#include <GL/glew.h>
#include <enschin/Window.h>
#include "scenes/GameScene.h"


int main(void)
{
    if (!glewInit()) exit(0);
    Window* window = new Window("sddgffk", { 480, 480 }, false);
    MyGame* mG = new MyGame();
    window->setClearColor(Color{ 0, 1, 1, 1 });
    window->startApp();
    mg->start(window, GameScene());
}