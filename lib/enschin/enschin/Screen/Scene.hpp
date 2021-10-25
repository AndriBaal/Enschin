#pragma once

class Scene {
private:

public:
	virtual void update() = 0;
	virtual void render() = 0;
};