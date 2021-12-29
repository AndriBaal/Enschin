#pragma once
#include <cassert>
#include <vector>
#include <GL/glew.h>

#define INT2VOIDP(i) (void*)(uintptr_t)(i)

struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned char normalized;
};

struct VertexBufferLayout {
private:
    unsigned int stride;
    std::vector<VertexBufferElement> elements;
    void push(unsigned int type, unsigned int count, unsigned char normalized);
public:
    VertexBufferLayout() : stride(0) { }

    void addFloat(unsigned int count);
    void addUnsignedInt(unsigned int count);
    void addUnsignedByte(unsigned int count);

    std::vector<VertexBufferElement> getElements() const { return elements; };
    unsigned int getStride() const { return stride; };
};