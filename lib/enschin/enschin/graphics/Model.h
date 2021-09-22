#pragma once
#include "buffer/VertexBuffer.h"
#include "buffer/VertexArray.h"
#include "buffer/VertexBufferLayout.hpp"
#include "buffer/IndexBuffer.h"

struct Model
{
private:
	const static unsigned int INDICES[];
	int amountOfVertices = 4;
	VertexArray* va;
	IndexBuffer* ib;

public:
	Model(float vertices[], int amountOfVertices = 4);
	const static unsigned int* getIndices() { return INDICES; }
	//float generateVertices();
	
	VertexArray* getVa() { return va; }
	IndexBuffer* getIb() { return ib; }
	int getamountOfVertices() { return amountOfVertices; }
};