#pragma once
#include <box2d/b2_chain_shape.h>
#include <box2d/b2_math.h>
#include "render_model.h"
#include "model.h"
#include "color.h"
#include <algorithm>

struct TerrainElement {
    RenderModel* model;
    Color color;
    void free() {
        delete model;
    }
};

class Terrain{
private:
    b2ChainShape ground;
    TerrainElement* elements;
    unsigned int amountOfElements;
public:
    Terrain(float* vertices, unsigned int amountOfVertices, bool collisionOutside=1);
    void free() const;
    b2ChainShape *getChainShape() { return &ground; }
    unsigned int getAmountOfElements() { return amountOfElements; };
    TerrainElement* getElements() { return elements; }
};