#pragma once
#include <enschin/util/ressources.hpp>
#include <enschin/input/input.h>

//Textures
#define TEST 10


//Input events
#define TEST_EVENT 2

namespace RessourceLoader {
    void loadGameRessources(Ressources& res);
    void loadGameInput(Input& input);
}