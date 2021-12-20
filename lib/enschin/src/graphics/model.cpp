#include <enschin/model.h>
#include <iostream>

const float Model::defaultTexCoords[8] = {
        0.0f, 0.0f, //Bottom left
        1.0f, 0.0f, //Bottom right
        1.0f, 1.0f, //Top right
        0.0f, 1.0f //Top left
};

const unsigned int Model::defaultIndices[6] = {0, 1, 2, 2, 3, 0};

Model::~Model() {
    delete shape;
    delete localBuffer;
}

/**
 * @brief Construct a new Model object. Mostly used
 * for unordinary Models that have more than 4 vertices.
 *
 * @param vertices Vertices(corners) of the model
 * @param amountOfVertices Amount of Vertices for a model (default=4)
 * @param indicies Indices (draw order of triangles) of the model (default=[0, 1, 2, 2, 3, 0])
 * @param amountOfIndices Amount of Indices of the model (default=6)
 */

Model::Model(const float vertices[], const bool chain, const unsigned short amountOfVertices,
             const unsigned int indices[], const unsigned short amountOfIndices)
        : amountOfIndices(amountOfIndices), amountOfVertices(amountOfVertices),
          vb(vertices, 4 * amountOfVertices * sizeof(float)),
          ib(indices, amountOfIndices), va(1) {

    b2Vec2 b2vertices[amountOfVertices];
    for (int i = 0; i < amountOfVertices*4; i+=4) {
        b2vertices[i/4].Set(vertices[i], vertices[i+1]);
    }

    if (chain) {
        std::reverse(b2vertices, b2vertices + sizeof(b2vertices)/sizeof(b2vertices[0]));
        b2ChainShape* chainShape = new b2ChainShape;
        chainShape->CreateLoop(b2vertices, amountOfVertices);
        shape = chainShape;
    } else {
        b2PolygonShape* polygonShape = new b2PolygonShape;
        polygonShape->Set(b2vertices, amountOfVertices);
        shape = polygonShape;
    }

    VertexBufferLayout layout;
    layout.addFloat(2);
    layout.addFloat(2);

    va.addBuffer(vb, layout);
}

/**
 * @brief Construct a new Model that has 4 vertices.
 * The vertices get created automatically by the passed
 * Dimension.
 *
 * @param size Dimension of the Model
 * @param indicies Indices (draw order of triangles) of the model (default=[0, 1, 2, 2, 3, 0])
 * @param amountOfIndices Amount of Indices of the model (default=6)
 */
Model::Model(Vec2f size)
        : amountOfIndices(6), amountOfVertices(6),
          localBuffer(generateVerticesTex(size)),
          vb(localBuffer, 4 * amountOfVertices * sizeof(float)),
          ib(defaultIndices, amountOfIndices), va(1) {


    b2PolygonShape* polygonShape = new b2PolygonShape;
    polygonShape->SetAsBox(size.x / 2, size.y / 2);
    shape = polygonShape;

    VertexBufferLayout layout;
    layout.addFloat(2);
    layout.addFloat(2);

    va.addBuffer(vb, layout);
    delete localBuffer;
}

Model::Model(float radius)
    : amountOfIndices(6), amountOfVertices(6),
      localBuffer(generateVerticesTex({radius * 2, radius * 2})),
      vb(localBuffer, 4 * amountOfVertices * sizeof(float)),
      ib(defaultIndices, amountOfIndices), va(1) {

    b2CircleShape* circleShape = new b2CircleShape;
    circleShape->m_radius = radius;
    shape = circleShape;

    VertexBufferLayout layout;
    layout.addFloat(2);
    layout.addFloat(2);

    va.addBuffer(vb, layout);
    delete localBuffer;
}

/**
 * @brief Bind the model for rendering.
 */
void Model::bind() const{
    va.bind();
    ib.bind();
}


float* Model::generateVerticesTex(Vec2f dim) {
    auto* dest = new float[16];
    dest[4] = dim.x/2.0f;
    dest[8] = dim.x/2.0f;
    dest[0] = -dim.x/2.0f;
    dest[12] = -dim.x/2.0f;
    dest[9] = dim.y/2.0f;
    dest[13] = dim.y/2.0f;
    dest[1] = -dim.y/2.0f;
    dest[5] = -dim.y/2.0f;
    dest[2] = 0.0f;
    dest[3] = 0.0f;
    dest[7] = 0.0f;
    dest[14] = 0.0f;
    dest[6] = 1.0f;
    dest[15] = 1.0f;
    dest[10] = 1.0f;
    dest[11] = 1.0f;
    return dest;
}
