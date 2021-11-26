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
            body->ApplyForce({0, 1400}, body->GetPosition());
        }else{
            body->ApplyForce({0, 1000}, body->GetPosition());
        }
        jumps--;
    }
    if (ctx.input.getEvent("walk_backwards")) {
        body->ApplyForce({0, -1000}, body->GetPosition());
    }
    if (ctx.input.getEvent("walk_left")) {
        body->ApplyForce({-25, 0}, body->GetPosition());
    }
    if (ctx.input.getEvent("walk_right")) {
        body->ApplyForce({25, 0}, body->GetPosition());
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