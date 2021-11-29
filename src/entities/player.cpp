#include <game/player.h>

Player::Player(const UContext& ctx, Vec2 pos)
    : Entity(ctx, ctx.res.getModel("test_model"), ctx.res.getSprite("cute"), pos, 1.0f){
    jumpTimer = new Timer(0, .25f);
    ctx.timers.push_back(jumpTimer);
}

void Player::update(const UContext& ctx) {
    mousePos = ctx.input.getCursorPos();
    if (ctx.input.getEvent("walk_forward") && jumps && jumpTimer->take()){
        if (jumps >= 1){
            body->SetLinearVelocity({body->GetLinearVelocity().x, 0});
            body->ApplyLinearImpulseToCenter({0, 800 * ctx.deltaTime});
        }else{
            body->ApplyLinearImpulseToCenter({0, 800 * ctx.deltaTime});
        }
        jumps--;
    }
    if (ctx.input.getEvent("walk_backwards")) {
        body->ApplyLinearImpulseToCenter({0, -12});
    }
    if (ctx.input.getEvent("walk_left")) {
        body->ApplyLinearImpulseToCenter({-40 * ctx.deltaTime, 0});
    }
    if (ctx.input.getEvent("walk_right")) {
        body->ApplyLinearImpulseToCenter({40 * ctx.deltaTime, 0});
    }
}

void Player::render(const RContext& ctx) {
    ctx.renderer.translate(body->GetPosition());
    ctx.renderer.rotate(body->GetAngle());
    ctx.renderer.renderTexture(model, sprite.getTexture());
    ctx.renderer.rotate(-body->GetAngle());
    ctx.renderer.translate(-body->GetPosition());
}

void Player::onRelease() {
}

void Player::onCollision() {
    jumps = maxJumps;
}

void Player::onEntityCollision(Entity& entity) {

}