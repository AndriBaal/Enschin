#include <enschin/game_object.h>

void GameObject::createBody(const UpdateContext& ctx, Vec2 pos,
                            bool fixedRotation, bool collision, bool isStatic,
                            float gravity, float density, float friction) {

    b2BodyDef bodyDef;
    bodyDef.type = (isStatic) ? b2_staticBody : b2_dynamicBody;
    bodyDef.position.Set(pos.x, pos.y);
    bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
    body = ctx.world.CreateBody(&bodyDef);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = model->getCollisionShape();
    fixtureDef.density = density;
    fixtureDef.friction = friction;
    fixtureDef.isSensor = !collision;

    body->CreateFixture(&fixtureDef);
    body->SetFixedRotation(fixedRotation);
    body->SetGravityScale(gravity);

}

GameObject::GameObject(const UpdateContext &ctx, const std::string name, const Model* model, const SpriteSheet* sprite, Vec2 pos,
                       bool fixedRotation, bool isStatic, bool collision,
                       float gravity, float density, float friction)
                       : name(name), world(&ctx.world), model(model), sprite(sprite) {
    createBody(ctx, pos, fixedRotation, isStatic, collision, gravity, density, friction);
    ctx.chunkManager.addGameObject(this);
    renderType = SPRITE;
}

GameObject::GameObject(const UpdateContext &ctx, const std::string name, const Model *model, const Color* color, Vec2 pos,
                       bool fixedRotation, bool isStatic, bool collision,
                       float gravity, float density, float friction)
                       : name(name), world(&ctx.world), model(model), color(color) {
    createBody(ctx, pos, fixedRotation, isStatic, collision, gravity, density, friction);
    ctx.chunkManager.addGameObject(this);
    renderType = COLOR;
}

GameObject::GameObject(const UpdateContext &ctx, const std::string name, const Model *model, Vec2 pos,
                       bool fixedRotation, bool isStatic, bool collision,
                       float gravity, float density, float friction)
                        : name(name), world(&ctx.world), model(model) {
    createBody(ctx, pos, fixedRotation, isStatic, collision, gravity, density, friction);
    ctx.chunkManager.addGameObject(this);
    renderType = SHADER;
}

GameObject::~GameObject() {
    world->DestroyBody(body);
}

void GameObject::render(const RenderContext &ctx) {
    if (renderType != SHADER) {
        ctx.renderer.translate(body->GetPosition());
        ctx.renderer.rotate(body->GetAngle());
        switch (renderType) {
            case COLOR:
                if (model->getCollisionShape()->GetType() == b2Shape::e_circle) {
                    ctx.renderer.renderCircleColor(model, color);
                } else {
                    ctx.renderer.renderColor(model, color);
                }
                break;
            case SPRITE:
                if (model->getCollisionShape()->GetType() == b2Shape::e_circle) {
                    ctx.renderer.renderCircleTexture(model, sprite->getTexture());
                } else {
                    ctx.renderer.renderTexture(model, sprite->getTexture());
                }
                break;
        }
        ctx.renderer.rotate(-body->GetAngle());
        ctx.renderer.translate(-body->GetPosition());
    }
}
