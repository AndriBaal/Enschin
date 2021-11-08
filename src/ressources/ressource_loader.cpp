#include "ressource_loader.h"

namespace RessourceLoader {
    void loadGameRessources(Ressources& res) {
        res.models = {
                {"test_model", Model({0.5f, 0.5f})}
        };
        res.textures = {
                {"test_texture", Texture("./textures/bird.jpg")},
                };
        res.colors = {
                {"test_color", Color(0, 1, 0, 1)},
                };
    }

    void loadGameInput(Input& input) {
        input.inputEvents = {
                {TEST_EVENT, false}
        };
        input.keyboardMapping = {
                {TEST_EVENT, {83, false}}
        };
    }
}