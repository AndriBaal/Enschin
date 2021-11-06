#include "vertex_array.h"

unsigned int VertexArray::boundVertexArray = 0;

VertexArray::VertexArray() {
    glGenVertexArrays(1, &vertexArrayId);
}

VertexArray::~VertexArray() {
    if (created) {
        glDeleteVertexArrays(1, &vertexArrayId);
    }else{
        created=true;
    }
}

void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) const {
    bind();
    vb.bind();
    const std::vector<VertexBufferElement> elements = layout.getElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size() ; i++) {
        const VertexBufferElement element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), INT2VOIDP(offset));
        offset += element.count * VertexBufferElement::getSizeOfType(element.type);
    }
}

void VertexArray::bind() const {
    if (boundVertexArray != vertexArrayId) {
        boundVertexArray = vertexArrayId;
        glBindVertexArray(vertexArrayId);
    }
}

void VertexArray::unbind() {
    glBindVertexArray(0);
}