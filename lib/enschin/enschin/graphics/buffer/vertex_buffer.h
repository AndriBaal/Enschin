#pragma once
#include <GL/glew.h>

class VertexBuffer {
private:
    bool created = false;
    unsigned int vertexBufferId;
    static unsigned int boundVertexBuffer;
public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void bind() const;
    void unbind() const;
};