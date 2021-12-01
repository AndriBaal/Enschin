#pragma once
#include <box2d/b2_chain_shape.h>
#include <box2d/b2_math.h>
#include "render_model.h"
#include "model.h"
#include "color.h"
#include <algorithm>
#include <iostream>

struct TerrainElement {
    RenderModel model;
    Color color;
};

class Terrain{
private:
    b2ChainShape* ground;
    TerrainElement** elements;
    unsigned int amountOfElements;
public:
    Terrain(float* vertices, unsigned int amountOfVertices, bool collisionOutside=1);
    ~Terrain();
    b2ChainShape *getChainShape() const { return ground; }
    unsigned int getAmountOfElements() const { return amountOfElements; };
    TerrainElement** getElements() const { return elements; }
    TerrainElement* getElement(int index){ return elements[index]; }
};