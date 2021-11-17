#pragma once
#include <GLFW/glfw3.h>
#include <json/json.h>
#include <fstream>
#include <map>
#include "keyboard.h"
#include "mouse.h"
#include "vec2.h"

#define KEYMOUSE 0
#define CONTROLLER 1
#define TOUCH 2

class Input {
private:
    Mouse mouse;
    Keyboard keyboard;
    unsigned char inputType = 0;
    Vec2 cursorPos;
    std::unordered_map<std::string, bool> inputEvents; //TriggerId, triggered
//    std::unordered_map<int, bool> keyboardMapping; //Keycode bool
//    std::unordered_map<std::string, std::pair<int, bool>> mouseButtonsMapping; //TriggerId, Buttoncode
    // std::map<int, int> ControllerMapping; //TriggerId, Controllercode
    // std::map<int, GuiObject> TouchMapping; //TriggerId, Reactive touch component
public:
    Input() = default;
    Input(const std::string& inputEvents);
    void load(const std::string& eventPath);
    void update(GLFWwindow* window, float units);
    bool getEvent(const std::string& eventKey){ return inputEvents.at(eventKey); }
    Vec2 getCursorPos(){ return cursorPos; };
};
