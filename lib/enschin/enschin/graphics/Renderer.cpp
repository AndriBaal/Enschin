#include "Renderer.h"

ShaderProgram* Renderer::colorProgram = NULL;
ShaderProgram* Renderer::textureProgram = NULL;
ShaderProgram* Renderer::coloredTextureProgram = NULL;

glm::mat4* Renderer::proj = NULL;
glm::mat4* Renderer::view = NULL;
glm::mat4* Renderer::mvp = NULL;

float Renderer::ratio = 0;
float Renderer::units = 0;

void Renderer::init(Dim windowSize, float units)
{
    initShaderPrograms();

    Renderer::units = 100;
    Mouse::setUnits(units);
    resetProjection(windowSize);
}

void Renderer::initShaderPrograms()
{
	colorProgram = new ShaderProgram("./res/enschin/shader/vertex.vert", "./res/enschin/shader/color.frag");
    textureProgram = new ShaderProgram("./res/enschin/shader/vertex.vert", "./res/enschin/shader/texture.frag");
    coloredTextureProgram = new ShaderProgram("./res/enschin/shader/vertex.vert", "./res/enschin/shader/colored_texture.frag");
}


void Renderer::renderColor(Model& model, Color& color)
{
    model.getVa()->bind();
    model.getIb()->bind();

    colorProgram->bind();
    colorProgram->setUniformMat4f("u_MVP", *mvp);
    colorProgram->setColor("u_Color", color);

    glDrawElements(GL_TRIANGLES, model.getAmountOfIndices(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::renderTexture(Model& model, Texture& texture)
{
    model.getVa()->bind();
    model.getIb()->bind();
    texture.bind(); 
    textureProgram->bind();   
    textureProgram->setUniform1i("u_Texture", 0);
    textureProgram->setUniformMat4f("u_MVP", *mvp);

    glDrawElements(GL_TRIANGLES, model.getAmountOfIndices(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::renderColoredTexture(Model& model, Texture& texture, Color& color)
{
    model.getVa()->bind();
    model.getIb()->bind();
    texture.bind(); 
    coloredTextureProgram->bind();   
    coloredTextureProgram->setUniform1i("u_Texture", 0);
    coloredTextureProgram->setUniformMat4f("u_MVP", *mvp);
    coloredTextureProgram->setColor("u_Color", color);
    glDrawElements(GL_TRIANGLES, model.getAmountOfIndices(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::renderRaytracing(Model& model, float vertices[], int amountOfVertices, Light& light, std::vector<GameObject> objects)
{
    std::vector<Ray> intersectingLines = std::vector<Ray>();
    for(std::vector<GameObject>::iterator it = objects.begin(); it != objects.end(); it++) 
    {
        for(int i = 0; i < amountOfVertices; i++) 
        {
            // if (Physics::isLineIntersecting(it., )
            // {
            // }
        }
    }

}

// void Renderer::translateAndRender(){

// }

void Renderer::absoluteTranslate(Vec2 pos){
    //Renderer::mvp = new glm::mat4((*proj * *view * glm::translate(glm::mat4(1.0f), glm::vec3(pos.x, pos.y, 0))));
}

void Renderer::translate(Vec2 pos)
{
    Renderer::mvp = new glm::mat4(glm::translate(*mvp, glm::vec3(pos.x, pos.y, 0)));
}

void Renderer::rotate(float angle)
{
    Renderer::mvp = new glm::mat4(glm::rotate(*mvp, glm::radians(angle), glm::vec3(0.0f, 0.0f, 0.0f)));
}

void Renderer::scale(Vec2 scaling)
{

}

void Renderer::resetProjection(Dim windowSize)
{
    ratio = windowSize.getRatioWH();
    proj = new glm::mat4(glm::ortho(-ratio * units, ratio * units, -units, units, -units, units));
    glm::mat4 ident = glm::mat4(1.0f);
    glm::vec3 trvec = glm::vec3(0, 0, 0);
    view = new glm::mat4(glm::translate(ident, trvec));
    mvp = new glm::mat4((*proj * *view * glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))));


}