#pragma once
#include <GL/glew.h>

class VertexBuffer {
private:
    unsigned int vertexBufferId;
    static unsigned int boundVertexBuffer;
public:
    VertexBuffer() = default;
    ~VertexBuffer();
    VertexBuffer(const void* data, unsigned int size);

    void bind() const;
    static void unbind();
};