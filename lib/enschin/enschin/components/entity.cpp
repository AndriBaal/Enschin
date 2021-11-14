#include "entity.h"

unsigned int Entity::idCounter = 1;

Entity::Entity(Ressources& res, Vec2 pos, Dim2 dim, Vec2 dir)
    : pos(pos), dim(dim), dir(dir) {
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