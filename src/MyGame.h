#include <enschin/GameHandler.h>

class MyGame : public GameHandler
{

public:
    
	virtual void start(Window* window, Scene& startScene) override;
	virtual void updateCurrentScene() override;
}