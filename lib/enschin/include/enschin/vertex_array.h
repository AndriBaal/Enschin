#pragma once

#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"

struct VertexArray {
private:
    unsigned int vertexArrayId;
public:
    VertexArray() = default;
    VertexArray(unsigned int amount);
    ~VertexArray();
    void addBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout) const;
    void bind() const;
    static void unbind();
};