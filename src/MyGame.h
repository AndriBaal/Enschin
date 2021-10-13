#include <enschin/Window.h>
#include <enschin/GameHandler.h>
class MyGame : public GameHandler
{
private:
public:
	MyGame();
    virtual void process() override;
};