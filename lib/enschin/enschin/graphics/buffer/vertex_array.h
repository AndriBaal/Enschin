#pragma once
#include "vertex_buffer.h"
#include "vertex_buffer_layout.hpp"

class VertexArray {
private:
    bool created = false;
    unsigned int vertexArrayId;
    static unsigned int boundVertexArray;
public:
    VertexArray(bool b){}
    VertexArray();
    ~VertexArray();

    void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    void bind() const;
    void unbind() const;
};