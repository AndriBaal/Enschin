#pragma once
#include <math.h>
#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"
#include "vertex_array.h"
#include "index_buffer.h"
#include "dim2.h"

/**
 * @brief Model that holds all Buffers for rendering
 */
struct Model {
private:
    static float defaultTexCoords[8];
	static unsigned int defaultIndices[6];
	unsigned short amountOfVertices;
	unsigned short amountOfIndices;
	float* vertices;
	VertexArray va = (1);
	IndexBuffer ib;
    VertexBuffer vb;

public:
	Model() = default;
	Model(Dim2 size);
	Model(float vertices[],
		unsigned short amountOfVertices = 4,
		unsigned int indices[6] = defaultIndices,
		unsigned short amountOfIndices = 6,
        float texCoords[8] = defaultTexCoords);
    void free();

	static void generateVertices(Dim2 size, float dest[16]);
	static void generateVerticesTex(Dim2 size, float dest[]);
	void bind();
	int getAmountOfVertices() { return amountOfVertices; }
	unsigned int getAmountOfIndices() { return amountOfIndices; }
    float* getVertices() const { return vertices; }
};