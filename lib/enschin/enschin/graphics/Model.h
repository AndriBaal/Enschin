#pragma once
#include <math.h>
#include "enschin/graphics/buffer/VertexBuffer.h"
#include "enschin/graphics/buffer/VertexBufferLayout.hpp"
#include "enschin/graphics/buffer/VertexArray.h"
#include "enschin/graphics/buffer/IndexBuffer.h"
#include "enschin/math/Dim.h"

// struct Model {
// private:
// 	const static float texCoords[8];
// 	unsigned short amountOfVertices;
// 	unsigned short amountOfIndices;
// 	VertexArray* va;
// 	IndexBuffer* ib;

// public:
// 	Model(Dim size);
// 	Model(float vertices[], 
// 		unsigned short amountOfVertices = 4, 
// 		unsigned int indicies[6] = new unsigned int[6] {0, 1, 2, 2, 3, 0}, 
// 		unsigned short amountOfIndices = 6);
// 	//const static unsigned int* getIndices() { return INDICES; }
// 	//float generateVertices();
	
// 	VertexArray* getVa() { return va; }
// 	IndexBuffer* getIb() { return ib; }
// 	int getAmountOfVertices() { return amountOfVertices; }
// 	unsigned int getAmountOfIndices() { return amountOfIndices; }
// };

/**
 * @brief Model that holds all Buffers for rendering
 * 
 */
struct Model {
private:
	const static float texCoords[8];
	unsigned short amountOfVertices;
	unsigned short amountOfIndices;
	VertexArray va = VertexArray(1);
	IndexBuffer ib;

public:
	Model(Dim size);
	Model(float vertices[], 
		unsigned short amountOfVertices = 4, 
		unsigned int indicies[6] = new unsigned int[6] {0, 1, 2, 2, 3, 0}, 
		unsigned short amountOfIndices = 6);
	
	static void generateVertices(float source[], Dim size);
	VertexArray getVa() { return va; }
	IndexBuffer getIb() { return ib; }
	int getAmountOfVertices() { return amountOfVertices; }
	unsigned int getAmountOfIndices() { return amountOfIndices; }
};