#include "entity.h"

unsigned int Entity::idCounter = 1;

Entity::Entity(Model& model, SpriteSheet& sprite) : model(model), sprite(sprite){
    id = idCounter;
    idCounter += 1;
}

Entity::~Entity(){
	std::cout << "Killed: " << id << std::endl;
}
//void Entity::onDamage(float damage) {
//
//}
//
//void Entity::onEntityCollision()
//{
//
//}