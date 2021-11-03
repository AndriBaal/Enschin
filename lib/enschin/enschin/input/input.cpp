#include "input.h"

Input

void Input::update(GLFWwindow* window, float units) {
    switch (inputType) {
    case KEYMOUSE:
        keyboard.update(keyboardMapping);
        mouse.updateButtons(mouseButtonsMapping);
        mouse.updateCursor(units, cursorPos);
        for (auto event = inputEvents.begin(); event != inputEvents.end(); event++) {
            event->second = false;
            for (auto button = mouseButtonsMapping.begin(); button != mouseButtonsMapping.end(); button++)
                if (event->first == button->first && button->second.second) event->second = true;
            for (auto key = keyboardMapping.begin(); key != keyboardMapping.end(); key++)
                if (event->first == event-> second && key->second.second) event->second = true;
        }
        break;
    case CONTROLLER:

        break;
    case TOUCH:

        break;
    }
}