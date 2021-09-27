#include <enschin/Window.h>
#include <enschin/GameHandler.h>
#include "MyRenderer.h"
class MyGame : public GameHandler
{
private:
	MyRenderer* myRenderer;
public:
	MyGame(MyRenderer* myRenderer);
    virtual void update() override;
};