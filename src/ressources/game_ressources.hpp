#include "enschin/util/ressources.hpp"

struct GameRessources : public Ressources {
    virtual void load() {
        models = {
            {
                "test_model", Model({0.5f, 0.5f}),
            },
        };
        textures = {
            {"test_texture", Texture("./textures/bird.jpg")}, 
        };
        colors = {
            {"test_color", Color(0, 1, 0, 1)},
        };
    }
};