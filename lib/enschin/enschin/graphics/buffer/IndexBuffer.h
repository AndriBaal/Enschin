#pragma once
#include <assert.h>
#include <GL/glew.h>
#define ASSERT(x) if (!(x)) assert(false)
#define INT2VOIDP(i) (void*)(uintptr_t)(i)

class IndexBuffer
{
private:
    unsigned int indexBufferId;
    unsigned int count;

public:
    IndexBuffer(const unsigned int* indices, unsigned int count);
    ~IndexBuffer();

    void bind() const;
    void unbind() const;

    inline unsigned int getCount() const { return count; }
};