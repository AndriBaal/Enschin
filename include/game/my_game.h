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
    void start(const GContext& gtx) override;
    void loop(const GContext& gtx) override;
    void free() override;
};