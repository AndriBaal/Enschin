#include "Renderer.h"


void Renderer::init(Window* window)
{
    Dimension windowSize = window->getSize();
    Renderer::proj = new glm::mat4(glm::ortho(-windowSize.w / windowSize.h, windowSize.w / windowSize.h, -1.0f, 1.0f, -1.0f, 1.0f));
    glm::mat4 ident = glm::mat4(1.0f);
    glm::vec3 trvec = glm::vec3(0, 0, 0);
    Renderer::view = new glm::mat4(glm::translate(ident, trvec));
    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
    Renderer::mvp = new glm::mat4((*proj * *view * model));
}

Renderer::Renderer()
{
	colorProgram = new ShaderProgram("./res/enschin/shader/vertex.vert", "./res/enschin/shader/color.frag");
    textureProgram = new ShaderProgram("./res/enschin/shader/vertex.vert", "./res/enschin/shader/texture.frag");
    coloredTextureProgram = new ShaderProgram("./res/enschin/shader/vertex.vert", "./res/enschin/shader/colored_texture.frag");
}

void Renderer::renderColor(Model& model, const Color& color)
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

void Renderer::renderColoredTexture(Model& model, Texture& texture, const Color& color)
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


void Renderer::translate(Vector2 pos)
{

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
    //Dimension windowSize = window->getSize();
    //Renderer::proj = new glm::mat4(glm::ortho(-windowSize.h / windowSize.w, windowSize.h / windowSize.w, -1.0f, 1.0f, -1.0f, 1.0f));
}