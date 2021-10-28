#pragma once

#include "enschin/game.h"
#include "enschin/graphics/renderer.h"

/**
 * @brief Scenes that are meant to be used for different envirnments
 * For example between loading & game screen or for different rooms.
 */
class Game;
class Scene {
protected:
	Renderer renderer;
private:
	//lists for objets & entities
public:
	Scene(Game& game);
	virtual void update(Game& game, Window& window) = 0;
	virtual void render() = 0;
	Renderer& getRenderer(){ return renderer; }
};