#include <game/player.h>

Player::Player(const UpdateContext& ctx, Vec2f pos)
    : GameObject(ctx, "triangle", ctx.res.getModel("test_model"), ctx.res.getSprite("noah"), pos){
    jumpTimer = new Timer(0, .25f);
    ctx.camera.setCameraTarget(body);
    ctx.window.setClearColor(Color{1, 0, 0, 1});
}

void Player::update(const UpdateContext& ctx) {
    mousePos = ctx.input.getCursorPos();
    jumpTimer->update(ctx.deltaTime);
    std::cout << ctx.camera.getCameraPosition() << std::endl;
    if (ctx.input.isEvent("walk_forward") && jumps && jumpTimer->take()) {
        if (jumps >= 1) {
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
        ctx.camera.increaseFov(ctx.window.getSize(), ctx.deltaTime * 10);
    }

    if (ctx.input.isEvent("zoom_in")) {
        ctx.camera.increaseFov(ctx.window.getSize(), -ctx.deltaTime * 10);
    }
}

void Player::render(const RenderContext &ctx) {
    ctx.renderer.renderTexture(model, sprite->getTexture());
}

void Player::onCollision(const GameObject* go) {
    jumps = maxJumps;
}