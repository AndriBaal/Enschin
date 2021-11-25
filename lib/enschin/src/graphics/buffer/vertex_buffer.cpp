#include <enschin/vertex_buffer.h>

unsigned int VertexBuffer::boundVertexBuffer = 1231132;

VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
    glGenBuffers(1, &vertexBufferId);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void VertexBuffer::free() const{
    glDeleteBuffers(1, &vertexBufferId);
}

void VertexBuffer::bind() const {
    if (boundVertexBuffer != vertexBufferId) {
        boundVertexBuffer = vertexBufferId;
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
    }
}

void VertexBuffer::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}