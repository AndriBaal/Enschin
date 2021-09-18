#include <iostream>
#include "engine/Window.h"


int main(void)
{
    Window* window = new Window("sddgffk", { 480, 480 }, false);
    window->setClearColor(Color{ 0, 0, 1, 1 });
    window->startApp();
}