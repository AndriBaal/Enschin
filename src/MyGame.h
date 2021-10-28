#include <enschin/screen/Window.h>
#include <enschin/Game.h>
class MyGame : public Game {
private:
public:
	MyGame(std::string gameName, Dim2 windowSize, bool fullscreen);
    virtual void loop() override;
};