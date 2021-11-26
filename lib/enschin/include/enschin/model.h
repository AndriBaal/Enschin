#pragma once
#include "render_model.h"

/**
 * @brief Model that holds all Buffers for rendering with collsions
 */
struct Model : public RenderModel{
private:
    b2PolygonShape polygonShape;
    b2CircleShape circleShape;
public:
    Model(float radius);
	Model(Vec2 size);
	Model(const float vertices[],
          const unsigned short amountOfVertices = 4,
          const unsigned int indices[6] = defaultIndices,
          const unsigned short amountOfIndices = 6);
    const b2PolygonShape* getCollisionShape() const { return &polygonShape; }
};