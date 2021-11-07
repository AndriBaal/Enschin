#pragma once
#include <GLFW/glfw3.h>
#include <map>
#include "keyboard.h"
#include "mouse.h"
#include "enschin/math/vec2.h"

#define DIRECTION_UP 0
#define DIRECTION_RIGHT 1
#define DIRECTION_DOWN 2
#define DIRECTION_LEFT 3

#define KEYMOUSE 0
#define CONTROLLER 1
#define TOUCH 2

class Input {
private:
    Mouse mouse;
    Keyboard keyboard;
    unsigned char inputType = 0;
    unsigned short directionSpeeds[4]; //Direction speeds from 0 to 100% for each direction
    Vec2 cursorPos;
    // std::map<int, int> ControllerMapping; //TriggerId, Controllercode
    // std::map<int, GuiObject> TouchMapping; //TriggerId, Reactive touch component
public:
    std::unordered_map<int, bool> inputEvents; //TriggerId, triggered
    std::unordered_map<int, std::pair<int, bool>> keyboardMapping; //TriggerId, Keycode
    std::unordered_map<int, std::pair<int, bool>> mouseButtonsMapping; //TriggerId, Buttoncode
    Input() = default;
    Input(GLFWwindow*);
    void update(float units);
    bool isInput(int);
    Vec2& getCursorPos(){ return cursorPos; };
};
