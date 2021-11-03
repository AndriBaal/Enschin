#pragma once

#include "enschin/game.h"
#include "enschin/graphics/renderer.h"
#include "enschin/util/ressources.hpp"

/**
 * @brief Scenes that are meant to be used for different environments
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
	virtual void update(Game& game, Ressources& ressources) = 0;
	virtual void render(Ressources& ressources) = 0;
	Renderer& getRenderer(){ return renderer; }
}; 