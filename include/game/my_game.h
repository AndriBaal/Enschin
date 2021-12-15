#include <enschin/window.h>
#include <enschin/game.h>

#include <utility>
#include "game_scene.h"

class MyGame : public Game {
private:
    GameScene* myScene;
    Ressources* res;
    Input* input;
public:
    MyGame(std::string gameName, Vec2f windowSize, bool fullscreen)
    : Game(std::move(gameName), windowSize, fullscreen){}
    void start(const GameContext& gtx) override;
    void loop(const GameContext& gtx) override;
    void free() override;
};