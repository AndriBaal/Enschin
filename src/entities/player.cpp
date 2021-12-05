#include <game/player.h>

Player::Player(const UpdateContext& ctx, Vec2 pos)
    : GameObject(ctx, "player", ctx.res.getModel("crate"), ctx.res.getSprite("cute"), pos){
    jumpTimer = new Timer(0, .25f);
    ctx.timers.push_back(jumpTimer);
    ctx.camera.setCameraTarget(body);
}

void Player::update(const UpdateContext& ctx) {
    mousePos = ctx.input.getCursorPos();
    if (ctx.input.isEvent("walk_forward") && jumps && jumpTimer->take()){
        if (jumps >= 1){
            body->SetLinearVelocity({body->GetLinearVelocity().x, 0});
            body->ApplyLinearImpulseToCenter({0, 25});
        }else{
            body->ApplyLinearImpulseToCenter({0, 25});
        }
        jumps--;
    }
    if (ctx.input.isEvent("walk_backwards")) {
        body->ApplyLinearImpulseToCenter({0, -12});
    }
    if (ctx.input.isEvent("walk_left")) {
        body->ApplyLinearImpulseToCenter({-40 * ctx.deltaTime, 0});
    }
    if (ctx.input.isEvent("walk_right")) {
        body->ApplyLinearImpulseToCenter({40 * ctx.deltaTime, 0});
    }

    if (ctx.input.isEvent("zoom_out")) {
        ctx.camera.increaseFov(1);
    }

    if (ctx.input.isEvent("zoom_in")) {
        ctx.camera.increaseFov(-1);
    }
}

void Player::onCollision(const GameObject* go) {
    jumps = maxJumps;
}
