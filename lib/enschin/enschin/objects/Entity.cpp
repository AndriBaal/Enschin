#include "../../../headers/Entity.h"

Entity::Entity(std::string tag, Vector2 pos, Dimension dim, Vector2 dir)
	: tag(tag), pos(pos), dim(dim), dir(dir) {}

Entity::~Entity(){
	std::cout << "Killed: " << tag << std::endl;
}

void Entity::onDamage(float damage) {

}

void Entity::onEntityCollision()
{}