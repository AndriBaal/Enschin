#pragma once
#include <GL/glew.h>

class VertexBuffer {
private:
    unsigned int vertexBufferId;
    static unsigned int boundVertexBuffer;
public:
    VertexBuffer() = default;
    VertexBuffer(const void* data, unsigned int size);

    void free() const;
    void bind() const;
    static void unbind();
};