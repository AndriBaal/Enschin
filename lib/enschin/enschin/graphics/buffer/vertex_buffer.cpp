#include "vertex_buffer.h"

unsigned int VertexBuffer::boundVertexBuffer = 1231132;

VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
    glGenBuffers(1, &vertexBufferId);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() {
    if (created) {
        glDeleteBuffers(1, &vertexBufferId);
    }else{
        created = true;
    }
}

void VertexBuffer::bind() const {
    if (boundVertexBuffer != vertexBufferId) {
        boundVertexBuffer = vertexBufferId;
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
    }
}

void VertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}