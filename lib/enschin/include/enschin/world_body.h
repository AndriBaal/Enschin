#pragma once
#include <box2d/b2_chain_shape.h>
#include "render_model.h"
#include "context.h"

class WorldBody{
private:
    b2ChainShape ground;
    RenderModel* models;
public:
    WorldBody(float* vertices, unsigned int amountOfVertices);

    void render(const RContext& ctx);
    b2ChainShape* const getChainShape(){ return &ground; }
};