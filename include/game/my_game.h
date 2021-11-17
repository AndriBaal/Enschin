#include <enschin/window.h>
#include <enschin/game.h>
#include "game_scene.h"

class MyGame : public Game {
private:
    GameScene* myScene;
public:
    MyGame(std::string gameName, Dim2 windowSize, bool fullscreen)
    : Game(gameName, windowSize, fullscreen){}
    virtual void start() override;
    virtual void loop() override;
    virtual void free() override;
};