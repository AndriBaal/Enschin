#include "Entity.h"

Entity::Entity(std::string tag, Vec2 pos, Dim dim, Vec2 dir)
	: tag(tag), pos(pos), dim(dim), dir(dir) {}

Entity::~Entity(){
	std::cout << "Killed: " << tag << std::endl;
}

void Entity::onDamage(float damage) {

}

void Entity::onEntityCollision()
{
	
}