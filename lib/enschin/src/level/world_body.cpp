#include <enschin/world_body.h>

WorldBody::WorldBody(float *vertices, unsigned int amountOfVertices) {
    b2Vec2 groundVertices[amountOfVertices];
    models = new RenderModel[amountOfVertices * 2];

    ground.CreateChain()

    for (int i = 0; i < amountOfVertices; i ++) {
        groundVertices[i] = {vertices[i*4], vertices[i*4+1]};
    }
}