#include <enschin/window.h>
#include <enschin/game.h>

#include <utility>
#include "game_scene.h"

class MyGame : public Game {
private:
    GameScene* myScene;
public:
    MyGame(std::string gameName, Vec2 windowSize, bool fullscreen)
    : Game(std::move(gameName), windowSize, fullscreen){}
    void start() override;
    void loop() override;
    void free() override;
};