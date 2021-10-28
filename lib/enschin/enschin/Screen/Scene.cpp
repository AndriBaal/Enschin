#include "Scene.h"

Scene::Scene(Game& game) { 
    renderer = Renderer(game.getWindow().getSize());
}