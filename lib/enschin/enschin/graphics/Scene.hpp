#pragma once

class Renderer;
class Scene
{
private:

public:
	virtual void update() = 0;
	virtual void render(Renderer* renderer) = 0;
};