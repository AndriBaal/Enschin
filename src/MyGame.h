#include <enschin/Window.h>
#include <enschin/GameHandler.h>
#include "MyRenderer.h"
class MyGame : public GameHandler
{
private:
public:
	MyGame();
    virtual void process() override;
};