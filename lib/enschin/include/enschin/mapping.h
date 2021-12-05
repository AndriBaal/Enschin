#pragma once

enum MappingType {
    KEY,
    MOUSE_BUTTON,
    CONTROLLER
};

struct Mapping{
    MappingType mappingType;
    int key;
    bool* event;
};
