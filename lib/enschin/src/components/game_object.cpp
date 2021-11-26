#include <enschin/game_object.h>

GameObject::GameObject(const UContext &ctx, const Model &model, const SpriteSheet &sprite, Vec2 pos, float density,
                       float friction, bool visible, bool collision, bool fixedRotation)
                       : model(model), sprite(sprite), density(density), friction(friction), fixedRotation(fixedRotation),
                       visible(visible), collision(collision){
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