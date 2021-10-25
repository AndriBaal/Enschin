#include "Entity.h"


Entity::~Entity(){
	std::cout << "Killed: " << tag << std::endl;
}

void Entity::onDamage(float damage) {

}

void Entity::onEntityCollision()
{
	
}