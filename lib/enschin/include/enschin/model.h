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

/**
 * @brief Model that holds all Buffers for rendering
 */
struct Model {
private:
    float* buffer;
    const static float defaultTexCoords[8];
    const static unsigned int defaultIndices[6];
	unsigned short amountOfVertices;
	unsigned short amountOfIndices;
    const VertexArray va = (1);
    const IndexBuffer ib;
    const VertexBuffer vb;

    b2PolygonShape polygonShape;

public:
    Model(float radius);
	Model(Vec2 size);
	Model(const float vertices[],
          const unsigned short amountOfVertices = 4,
          const unsigned int indices[6] = defaultIndices,
          const unsigned short amountOfIndices = 6);
    void free() const;

	static float* generateVerticesTex(Vec2 size);
	void bind() const;

	int getAmountOfVertices() const { return amountOfVertices; }
	unsigned int getAmountOfIndices() const { return amountOfIndices; }
    const b2PolygonShape* getCollisionShape() const { return &polygonShape; }
};