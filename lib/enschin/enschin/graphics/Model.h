#pragma once
#include "buffer/VertexBuffer.h"
#include "buffer/VertexArray.h"
#include "buffer/VertexBufferLayout.hpp"
#include "buffer/IndexBuffer.h"

struct Model
{
private:
	unsigned short amountOfVertices;
	unsigned short amountOfIndicies;
	VertexArray* va;
	IndexBuffer* ib;

public:
	Model(float vertices[], unsigned short amountOfVertices = 4, unsigned int indicies[6] = new unsigned int[6]{0, 1, 2, 2, 3, 0}, unsigned short amountOfIndices = 6);
	//const static unsigned int* getIndices() { return INDICES; }
	//float generateVertices();
	
	VertexArray* getVa() { return va; }
	IndexBuffer* getIb() { return ib; }
	int getAmountOfVertices() { return amountOfVertices; }
	unsigned int getAmountOfIndicies() { return amountOfIndicies; }
};