#include <enschin/input.h>

Input::Input(const std::string& eventPath) {
    load(eventPath);
}

void Input::update(GLFWwindow* window, float fov) {
    switch (inputType) {
    case KEYMOUSE:
//        keyboard.update(keyboardMapping);
//        mouse.updateButtons(mouseButtonsMapping);
//        mouse.updateCursor(units, cursorPos);
//        for (auto event = inputEvents.begin(); event != inputEvents.end(); event++) {
//            event->second = false;
//            for (auto button = mouseButtonsMapping.begin(); button != mouseButtonsMapping.end(); button++)
//                if (event->first == button->first && button->second.second) event->second = true;
//            for (auto key = keyboardMapping.begin(); key != keyboardMapping.end(); key++)
//                if (event->first == key->first && key->second.second) event->second = true;
//        }
        keyboard.update(window);
        mouse.updateCursor(window, fov, cursorPos);
        break;
    case CONTROLLER:


        break;
    case TOUCH:

        break;
    }
}

void Input::load(const std::string& eventPath) {
    std::ifstream eventStream(eventPath, std::ifstream::binary);
    Json::Reader eventReader;
    Json::Value eventValues;
    eventReader.parse(eventStream, eventValues);
    for (const auto& s : eventValues["events"]) {
        inputEvents.insert({ s.asString(), 1});
    }
    if (eventValues.isMember("keyboard_mapping")) {
        std::ifstream keyboardStream(eventValues["keyboard_mapping"].asString(), std::ifstream::binary);
        Json::Reader keyboardReader;
        Json::Value keyboardValues;
        keyboardReader.parse(keyboardStream, keyboardValues);

        std::vector<Mapping> keyMaps;

        for (auto & inputEvent : inputEvents) {
            if (keyboardValues.isMember(inputEvent.first)) {
                int key = keyboardValues[inputEvent.first].asInt();
                if (key < 10)
                    keyMaps.push_back({MOUSE_BUTTON, keyboardValues[inputEvent.first].asInt(), &inputEvent.second});
                else
                    keyMaps.push_back({KEY, keyboardValues[inputEvent.first].asInt(), &inputEvent.second});
            }
            inputEvent.second = 1;
        }
        keyboard = Keyboard(keyMaps);
    }
}