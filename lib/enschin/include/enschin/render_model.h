#pragma once
#include <math.h>
#include <box2d/b2_body.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>
#include <box2d/b2_circle_shape.h>
#include <box2d/b2_chain_shape.h>
#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"
#include "vertex_array.h"
#include "index_buffer.h"
#include "vec2.h"

#include <iostream>
/**
 * @brief Model for rendering without collisions
 */
struct RenderModel {
protected:
    float* buffer;
    const static float defaultTexCoords[8];
    const static unsigned int defaultIndices[6];
    unsigned short amountOfVertices;
    unsigned short amountOfIndices;
    const VertexArray va;
    const IndexBuffer ib;
    const VertexBuffer vb;

public:
    RenderModel(float radius);
    RenderModel(Vec2 size);
    RenderModel(const float vertices[],
          const unsigned short amountOfVertices = 4,
          const unsigned int indices[6] = defaultIndices,
          const unsigned short amountOfIndices = 6);

    static float* generateVerticesTex(Vec2 size);
    void bind() const;

    int getAmountOfVertices() const { return amountOfVertices; }
    unsigned int getAmountOfIndices() const { return amountOfIndices; }
};