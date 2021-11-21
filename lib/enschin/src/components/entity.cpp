#include <enschin/entity.h>

unsigned int Entity::idCounter = 1;

Entity::Entity(Scene& scene, Model& model, SpriteSheet& sprite, Vec2 pos, float density, float friction, bool fixedRotation)
    : model(model), sprite(sprite), pos(pos), density(density), friction(friction), fixedRotation(fixedRotation){
    scene.addEntity(this);
    id = idCounter;
    idCounter += 1;

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(pos.x, pos.y);
    body = scene.getWorld().CreateBody(&bodyDef);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &model.getCollisionShape();
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