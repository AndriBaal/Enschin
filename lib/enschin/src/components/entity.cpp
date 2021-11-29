#include <enschin/entity.h>


Entity::Entity(const UpdateContext& ctx, const Model& model, const SpriteSheet& sprite, Vec2 pos, float density, float friction, bool fixedRotation)
    : GameObject(ctx, model, sprite, pos, density, friction, fixedRotation){
    body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
    
}

Entity::~Entity(){
	std::cout << "Killed Entity" << std::endl;
}
//void Entity::onDamage(float damage) {
//
//}
//
//void Entity::onEntityCollision()
//{
//
//}