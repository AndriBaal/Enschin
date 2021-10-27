#pragma once

/**
 * @brief Scenes that are meant to be used for different envirnments
 * For example between loading & game screen or for different rooms.
 */
class Scene {
private:

public:
	virtual void update() = 0;
	virtual void render() = 0;
};