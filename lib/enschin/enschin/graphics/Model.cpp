#include "Model.h"
#include <iostream>
// 0, 1, 2,
// 2, 3, 0 Indicies for 4 corners

// 1, 2, 3,
// 0, 4, 5,
// 0, 1, 3,
// 0, 4, 3 Hexagon

// 2, 3, 4,
// 2, 4, 0,
// 0, 1, 2, Pentagon

const float Model::texCoords[8] = {
    0.0f, 0.0f, //Bottom left
    1.0f, 0.0f, //Bottom right
    1.0f, 1.0f, //Top right
    0.0f, 1.0f //Top left
};


/**
 * @brief Construct a new Model object. Mostly used
 * for unordinary Models that have more than 4 vertices.
 * 
 * @param vertices Vertices(corners) of the model
 * @param amountOfVertices Amount of Vertices for a model (default=4)
 * @param indicies Indices (draw order of triangles) of the model (default=[0, 1, 2, 2, 3, 0])
 * @param amountOfIndices Amount of Indices of the model (default=6)
 */
Model::Model(float vertices[], unsigned short amountOfVertices, unsigned int indices[], unsigned short amountOfIndices)
    : amountOfIndices(amountOfIndices), amountOfVertices(amountOfVertices) {
    float verticesTexCoord[amountOfVertices*4];
    for (int i = 0; i < amountOfVertices*4; i+=4) {
        verticesTexCoord[i] = vertices[i/2];
        verticesTexCoord[i+1] = vertices[i/2+1];
        if (i/2+1 < 8) {
            verticesTexCoord[i+2] = texCoords[i/2];
            verticesTexCoord[i+3] = texCoords[i/2+1];
        } else {
            verticesTexCoord[i+2] = texCoords[0];
            verticesTexCoord[i+3] = texCoords[0];
        }
    }
    VertexBuffer vb = VertexBuffer(verticesTexCoord, 4 * amountOfVertices * sizeof(float));
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
 */
Model::Model(Dim size) {

}

/**
 * @brief Writes 4 vertices into the given array based on the wished dimension.
 * 
 * @param dest Destination array
 * @param size Dimension of Model
 * @return float[] 
 */
void Model::generateVertices(float dest[], Dim size) {

}