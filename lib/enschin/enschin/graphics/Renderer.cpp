#include "Renderer.h"
#include <iostream>

ShaderProgram* Renderer::colorProgram = NULL;
ShaderProgram* Renderer::textureProgram = NULL;
ShaderProgram* Renderer::coloredTextureProgram = NULL;

glm::mat4* Renderer::proj = NULL;
glm::mat4* Renderer::view = NULL;
glm::mat4* Renderer::mvp = NULL;

float Renderer::ratio = 0;
float Renderer::units = 0;

void Renderer::init(Window* window, float units)
{
    initShaderPrograms();

    ratio = window->getSize().getRatioWH();
    units = 100;
    Mouse::setUnits(units);
    Renderer::proj = new glm::mat4(glm::ortho(-ratio * units, ratio * units, -units, units, -units, units));
    glm::mat4 ident = glm::mat4(1.0f);
    glm::vec3 trvec = glm::vec3(0, 0, 0);
    Renderer::view = new glm::mat4(glm::translate(ident, trvec));
    Renderer::mvp = new glm::mat4((*proj * *view * glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))));
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

    glDrawElements(GL_TRIANGLES, model.getAmountOfIndicies(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::renderTexture(Model& model, Texture& texture)
{
    model.getVa()->bind();
    model.getIb()->bind();
    texture.bind(); 
    textureProgram->bind();   
    textureProgram->setUniform1i("u_Texture", 0);
    textureProgram->setUniformMat4f("u_MVP", *mvp);

    glDrawElements(GL_TRIANGLES, model.getAmountOfIndicies(), GL_UNSIGNED_INT, nullptr);
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
    glDrawElements(GL_TRIANGLES, model.getAmountOfIndicies(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::renderRaytracing(Model& model, Light& light, std::vector<GameObject> objects)
{
    
}

// void Renderer::translateAndRender(){

// }

void Renderer::absoluteTranslate(Vector2 pos){
    Renderer::mvp = new glm::mat4((*proj * *view * glm::translate(glm::mat4(1.0f), glm::vec3(pos.x, pos.y, 0))));
}

void Renderer::translate(Vector2 pos)
{
    Renderer::mvp = new glm::mat4((*mvp * glm::translate(glm::mat4(1.0f), glm::vec3(pos.x, pos.y, 0))));
}

void Renderer::rotate(float angle)
{

}

void Renderer::scale(Vector2 scaling)
{

}

void Renderer::apply()
{

}

void Renderer::resetProjection(Window* window)
{
    ratio = window->getSize().getRatioWH();
    Mouse::setUnits(units);
    Renderer::proj = new glm::mat4(glm::ortho(-ratio * units, ratio * units, -units, units, -10.0f, 10.0f));
    Renderer::mvp = new glm::mat4((*proj * *view * glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))));
}