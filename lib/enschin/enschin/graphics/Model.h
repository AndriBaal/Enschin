#pragma once
#include <math.h>
#include "enschin/graphics/buffer/vertex_buffer.h"
#include "enschin/graphics/buffer/vertex_buffer_layout.hpp"
#include "enschin/graphics/buffer/vertex_array.h"
#include "enschin/graphics/buffer/index_buffer.h"
#include "enschin/math/dim2.h"

/**
 * @brief Model that holds all Buffers for rendering
 */
struct Model {
private:
	const static float texCoords[8];
	unsigned short amountOfVertices;
	unsigned short amountOfIndices;
	VertexArray* va;
	IndexBuffer* ib;

public:
	Model(Dim2 size);
	Model(float vertices[], 
		unsigned short amountOfVertices = 4, 
		unsigned int indices[6] = new unsigned int[6]{0, 1, 2, 2, 3, 0}, 
		unsigned short amountOfIndices = 6);
	
	static void generateVertices(Dim2 size, float dest[16]);
	static void generateVerticesTex(Dim2 size, float dest[]);
	VertexArray* getVa() { return va; }
	IndexBuffer* getIb() { return ib; }
	int getAmountOfVertices() { return amountOfVertices; }
	unsigned int getAmountOfIndices() { return amountOfIndices; }
};