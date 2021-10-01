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

Renderer::Renderer(){
	colorProgram = new ShaderProgram("./res/enschin/shader/vertex.vert", "./res/enschin/shader/color.frag");
}

void Renderer::renderTest(Model& m, Texture& t)
{
    m.getVa()->bind();
    m.getIb()->bind();

    t.bind();
    colorProgram->setUniform1i("u_Texture", 0);

    colorProgram->bind();
    colorProgram->setUniformMat4f("u_MVP", *mvp);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

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