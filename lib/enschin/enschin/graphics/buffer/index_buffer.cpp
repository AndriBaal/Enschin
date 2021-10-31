#include "index_buffer.h"

/**
 * @brief Construct a new Index Buffer by the given Indices.
 * Creates Buffer on the GPU memory.

 * @param indices Indices for the Buffer
 * @param count Count of Indices
 */
IndexBuffer::IndexBuffer(const unsigned int* indices, unsigned int count) {
    ASSERT(sizeof(unsigned int) == sizeof(GLuint));

    glGenBuffers(1, &indexBufferId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW);
}

/**
 * @brief Destroy the Index Index Buffer object and 
 * delete the Buffer on the GPU.
 */
IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &indexBufferId);
}

/**
 * @brief Bind Buffer for drawing
 */
void IndexBuffer::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);
}

/**
 * @brief Unbind Buffer
 */
void IndexBuffer::unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}