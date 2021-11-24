#include <enschin/model.h>
// 0, 1, 2,
// 2, 3, 0 Indicies for 4 corners

// 1, 2, 3,
// 0, 4, 5,
// 0, 1, 3,
// 0, 4, 3 Hexagon

// 2, 3, 4,
// 2, 4, 0,
// 0, 1, 2, Pentagon


float Model::defaultTexCoords[8] = {
    0.0f, 0.0f, //Bottom left
    1.0f, 0.0f, //Bottom right
    1.0f, 1.0f, //Top right
    0.0f, 1.0f //Top left
};

unsigned int Model::defaultIndices[6] = {0, 1, 2, 2, 3, 0};

/**
 * @brief Construct a new Model object. Mostly used
 * for unordinary Models that have more than 4 vertices.
 * 
 * @param vertices Vertices(corners) of the model
 * @param amountOfVertices Amount of Vertices for a model (default=4)
 * @param indicies Indices (draw order of triangles) of the model (default=[0, 1, 2, 2, 3, 0])
 * @param amountOfIndices Amount of Indices of the model (default=6)
 */
#include <iostream>
Model::Model(float vertices[], unsigned short amountOfVertices, unsigned int indices[], unsigned short amountOfIndices, float texCoords[])
    : amountOfIndices(amountOfIndices), amountOfVertices(amountOfVertices) {
    b2Vec2 b2vertices[amountOfVertices];
    for (int i = 0; i < amountOfVertices*4; i+=4) {
        b2vertices[i/4].Set(vertices[i], vertices[i+1]);
        std::cout << vertices[i] << "     " << vertices[i+1] << std::endl;
    }
    collisionShape.Set(b2vertices, amountOfVertices);

    vb = VertexBuffer(vertices, 4 * amountOfVertices * sizeof(float));
    ib = IndexBuffer(indices, amountOfIndices);

    VertexBufferLayout layout;
    layout.addFloat(2);
    layout.addFloat(2);

    va = VertexArray();
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

Model::Model(Vec2 size) {
    float verticesTexCoord[16] = {};
    amountOfIndices = 6;
    amountOfVertices = 4;

    generateVerticesTex(size, verticesTexCoord);

    collisionShape.SetAsBox(size.x/2, size.y/2);

    vb = VertexBuffer(verticesTexCoord, 4 * amountOfVertices * sizeof(float));
    ib = IndexBuffer(defaultIndices, amountOfIndices);

    VertexBufferLayout layout;
    layout.addFloat(2);
    layout.addFloat(2);

    va = VertexArray();
    va.addBuffer(vb, layout);
}

/**
 * Delete all the buffers of the model.
 */
void Model::free() {
    va.free();
    vb.free();
    ib.free();
}

/**
 * @brief Bind the model for rendering.
 */
void Model::bind() {
    va.bind();
    ib.bind();
}

/**
 * @brief Writes 4 vertices into the given array based on the wished dimension.
 * 
 * @param dim Dimension of Verticces
 * @param dest Destination array
 */
void Model::generateVertices(Vec2 dim, float dest[]) {
    dest[2] = dim.x/2.0f;
    dest[4] = dim.x/2.0f;
    dest[0] = -dim.x/2.0f;
    dest[6] = -dim.x/2.0f;
    dest[5] = dim.y/2.0f;
    dest[7] = dim.y/2.0f;
    dest[1] = -dim.y/2.0f;
    dest[3] = -dim.y/2.0f;
}

/**
 * @brief Writes 4 vertices and the texture coordinates into the given array.
 * 
 * @param dim Dimension of the vertices
 * @param dest Destination array
 */
void Model::generateVerticesTex(Vec2 dim, float dest[16]) {
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
}
