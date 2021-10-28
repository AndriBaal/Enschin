#pragma once
#include "vertex_buffer.h"
#include "vertex_buffer_layout.hpp"

class VertexArray {
private:
    unsigned int vertexArrayId;

public:
    VertexArray();
    ~VertexArray();

    void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    void bind() const;
    void unbind() const;
};