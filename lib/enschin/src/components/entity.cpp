#include <enschin/entity.h>

unsigned int Entity::idCounter = 1;

Entity::Entity(Scene& scene, Model& model, SpriteSheet& sprite) : model(model), sprite(sprite){
    id = idCounter;
    idCounter += 1;

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    body = scene.getWorld().CreateBody(&bodyDef);

    // Move to model
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(15.0f, 15.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    ///Move to model

    body->CreateFixture(&fixtureDef);
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