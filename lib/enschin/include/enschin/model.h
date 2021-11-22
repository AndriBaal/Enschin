#pragma once
#include <math.h>
#include <box2d/b2_body.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>
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
    static float defaultTexCoords[8];
	static unsigned int defaultIndices[6];
	unsigned short amountOfVertices;
	unsigned short amountOfIndices;
	VertexArray va = (1);
	IndexBuffer ib;
    VertexBuffer vb;

    b2PolygonShape collisionShape;

public:
	Model() = default;
	Model(Vec2 size);
	Model(float vertices[],
		unsigned short amountOfVertices = 4,
		unsigned int indices[6] = defaultIndices,
		unsigned short amountOfIndices = 6,
        float texCoords[8] = defaultTexCoords);
    void free();

	static void generateVertices(Vec2 size, float dest[16]);
	static void generateVerticesTex(Vec2 size, float dest[]);
	void bind();

	int getAmountOfVertices() { return amountOfVertices; }
	unsigned int getAmountOfIndices() { return amountOfIndices; }
    b2PolygonShape* getCollisionShape(){ return &collisionShape; }
};