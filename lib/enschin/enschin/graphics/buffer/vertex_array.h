#pragma once
#include "vertex_buffer.h"
#include "vertex_buffer_layout.hpp"

class VertexArray {
private:
    unsigned int vertexArrayId;
    static unsigned int boundVertexArray;
public:
    VertexArray(bool b){}
    VertexArray();

    void free();
    void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) const;
    void bind() const;
    static void unbind() ;
};