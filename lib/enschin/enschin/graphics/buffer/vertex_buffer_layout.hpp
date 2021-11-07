#pragma once
#include <cassert>
#include <vector>
#include <GL/glew.h>

#define INT2VOIDP(i) (void*)(uintptr_t)(i)

struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int getSizeOfType(unsigned int type) {
        switch (type) {
            case GL_FLOAT: return sizeof(GLfloat);
            case GL_UNSIGNED_INT: return sizeof(GLuint);
            case GL_UNSIGNED_BYTE: return sizeof(GLbyte);
        }
        return 0;
    }
};

class VertexBufferLayout {
private:
    unsigned int stride;
    std::vector<VertexBufferElement> elements;

public:
    VertexBufferLayout() : stride(0) { }

    void addFloat(unsigned int count) { push(GL_FLOAT, count, GL_FALSE); }
    void addUnsignedInt(unsigned int count) { push(GL_UNSIGNED_INT, count, GL_FALSE); }
    void addUnsignedByte(unsigned int count) { push(GL_UNSIGNED_BYTE, count, GL_TRUE); }

    inline std::vector<VertexBufferElement> getElements() const { return elements; };
    inline unsigned int getStride() const { return stride; };

private:
    void push(unsigned int type, unsigned int count, unsigned char normalized) {
        VertexBufferElement vbe = { type, count, normalized };
        elements.push_back(vbe);
        stride += count * VertexBufferElement::getSizeOfType(type);
    };
};