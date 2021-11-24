#pragma once

#include <GLFW/glfw3.h>
#include <json/json.h>
#include <fstream>
#include <map>
#include "keyboard.h"
#include "mouse.h"
#include "vec2.h"
#include "mapping.h"

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
public:
    Input() = default;

    Input(const std::string &inputEvents);
    void load(const std::string &eventPath);
    void update(GLFWwindow *window, float units);
    bool getEvent(const std::string &eventKey) { return inputEvents.at(eventKey); }
    Vec2 getCursorPos() { return cursorPos; };
};
