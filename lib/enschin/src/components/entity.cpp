#include <enschin/entity.h>

unsigned int Entity::idCounter = 1;

Entity::Entity(const UContext& ctx, const Model& model, const SpriteSheet& sprite, Vec2 pos, float density, float friction, bool fixedRotation)
    : model(model), sprite(sprite), density(density), friction(friction), fixedRotation(fixedRotation){
    ctx.entities.push_back(this);
    id = idCounter++;

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(pos.x, pos.y);
    bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
    body = ctx.world.CreateBody(&bodyDef);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = model.getCollisionShape();
    fixtureDef.density = density;
    fixtureDef.friction = friction;

    body->CreateFixture(&fixtureDef);
    body->SetFixedRotation(fixedRotation);
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