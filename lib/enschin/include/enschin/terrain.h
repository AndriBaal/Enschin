#pragma once
#include <box2d/b2_chain_shape.h>
#include <box2d/b2_math.h>
#include "model.h"
#include "model.h"
#include "color.h"
#include <algorithm>
#include <iostream>


class Terrain{
private:
    b2ChainShape* ground;
    Model** models;
    unsigned int amountOfElements;
public:
    Terrain(float* vertices, unsigned int amountOfVertices, bool collisionOutside=1);
    ~Terrain();
    b2ChainShape *getChainShape() const { return ground; }
    unsigned int getAmountOfElements() const { return amountOfElements; };
    Model** getElements() const { return models; }
    Model* getElement(int index){ return models[index]; }
};