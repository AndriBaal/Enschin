#pragma once
#include "VertexBuffer.h"
#include "VertexBufferLayout.hpp"

class VertexArray
{
private:
    unsigned int vertexArrayId;

public:
    VertexArray();
    ~VertexArray();

    void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    void bind() const;
    void unbind() const;
};