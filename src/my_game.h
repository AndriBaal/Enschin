#include "enschin/screen/window.h"
#include "enschin/game.h"
#include "scenes/game_scene.h"
#include "ressources/ressource_loader.h"

class MyGame : public Game {
private:
public:
	MyGame(std::string gameName, Dim2 windowSize, bool fullscreen);
    virtual void loop() override;
};