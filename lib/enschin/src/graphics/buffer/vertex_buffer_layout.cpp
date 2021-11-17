#include "vertex_buffer_layout.h"

void VertexBufferLayout::addFloat(unsigned int count) {
    push(GL_FLOAT, count, GL_FALSE);
}

void VertexBufferLayout::addUnsignedInt(unsigned int count) {
    push(GL_UNSIGNED_INT, count, GL_FALSE);
}

void VertexBufferLayout::addUnsignedByte(unsigned int count) {
    push(GL_UNSIGNED_BYTE, count, GL_TRUE);
}

void VertexBufferLayout::push(unsigned int type, unsigned int count, unsigned char normalized) {
    VertexBufferElement vbe = { type, count, normalized };
    elements.push_back(vbe);
    stride += count * sizeof(type);
};