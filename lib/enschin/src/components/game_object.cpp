#include <enschin/game_object.h>

void GameObject::createBody(const UpdateContext& ctx, Vec2 pos, float density, float friction, bool collision, bool fixedRotation) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(pos.x, pos.y);
    bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
    body = ctx.world.CreateBody(&bodyDef);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = model->getCollisionShape();
    fixtureDef.density = density;
    fixtureDef.friction = friction;

    body->CreateFixture(&fixtureDef);
    body->SetFixedRotation(fixedRotation);
}

GameObject::GameObject(const UpdateContext &ctx, const Model* model, const SpriteSheet* sprite, Vec2 pos, float density,
                       float friction, bool collision, bool fixedRotation)
                       : world(&ctx.world), model(model), sprite(sprite), density(density), friction(friction), fixedRotation(fixedRotation), collision(collision) {
    createBody(ctx, pos, density, friction, collision, fixedRotation);
    renderType = SPRITE;
}

GameObject::GameObject(const UpdateContext &ctx, const Model *model, const Color* color, Vec2 pos, float density, float friction,
                       bool collision, bool fixedRotation)
                       : world(&ctx.world), model(model), color(color), density(density), friction(friction), fixedRotation(fixedRotation), collision(collision) {
    createBody(ctx, pos, density, friction, collision, fixedRotation);
    renderType = COLOR;
}

GameObject::~GameObject() {
    world->DestroyBody(body);
}

void GameObject::render(const RenderContext &ctx) {
    ctx.renderer.translate(body->GetPosition());
    ctx.renderer.rotate(body->GetAngle());
    switch (renderType) {
        case COLOR:
            if (model->getCollisionType() == CIRCLE) {
                ctx.renderer.renderCircleColor(model, color);
            } else {
                ctx.renderer.renderColor(model, color);
            }
            break;
        case SPRITE:
            if (model->getCollisionType() == CIRCLE) {
                ctx.renderer.renderTexture(model, sprite->getTexture());
            } else {
                ctx.renderer.renderTexture(model, sprite->getTexture());
            }
            break;
        case SHADER:

            break;
    }
    ctx.renderer.rotate(body->GetAngle());
    ctx.renderer.translate(body->GetPosition());
}


void GameObject::update(const UpdateContext &ctx) {

}