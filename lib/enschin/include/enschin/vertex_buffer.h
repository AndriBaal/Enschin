#pragma once
#include <GL/glew.h>

class VertexBuffer {
private:
    unsigned int vertexBufferId;
public:
    VertexBuffer() = default;
    ~VertexBuffer();
    VertexBuffer(const void* data, unsigned int size);

    void bind() const;
    static void unbind();
};