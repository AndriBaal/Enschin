#pragma once
#include <assert.h>
#include <GL/glew.h>
#define ASSERT(x) if (!(x)) assert(false)
#define INT2VOIDP(i) (void*)(uintptr_t)(i)

/**
 * @brief IndeBuffer for storing indices (triangle draw order)
 * 
 */
class IndexBuffer {
private:
    unsigned int indexBufferId;

public:
    IndexBuffer() = default;
    IndexBuffer(const unsigned int* indices, unsigned int count);
    ~IndexBuffer();

    void bind() const;
    void unbind() const;
};