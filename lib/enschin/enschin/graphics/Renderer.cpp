#include "Renderer.h"

ShaderProgram* Renderer::colorProgram = NULL;
ShaderProgram* Renderer::textureProgram = NULL;
ShaderProgram* Renderer::coloredTextureProgram = NULL;

float Renderer::view[16] = {0};
float Renderer::proj[16] = {0};
float Renderer::mvp[16] = {0};

float Renderer::ratio = 0;
float Renderer::units = 0;

void Renderer::init(Dim windowSize, float units)
{
    initShaderPrograms();

    Renderer::units = units;
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
    colorProgram->setUniformMat4f("u_MVP", mvp);
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
    textureProgram->setUniformMat4f("u_MVP", mvp);

    glDrawElements(GL_TRIANGLES, model.getAmountOfIndices(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::renderColoredTexture(Model& model, Texture& texture, Color& color)
{
    model.getVa()->bind();
    model.getIb()->bind();
    texture.bind(); 
    coloredTextureProgram->bind();   
    coloredTextureProgram->setUniform1i("u_Texture", 0);
    coloredTextureProgram->setUniformMat4f("u_MVP", mvp);
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
    Matrix::translate(view, 0, pos.x, pos.y, 0);
    Matrix::multiply(mvp, proj, view);
}

void Renderer::rotate(float angle)
{
    Matrix::rotate(view, 0.0f, angle, 1.0f, 0.0f, 0.0f);
    Matrix::multiply(mvp, proj, view);
    //Renderer::mvp = new glm::mat4(glm::rotate(*mvp, glm::radians(angle), glm::vec3(0.0f, 0.0f, 0.0f)));
}

void Renderer::scale(Vec2 scaling)
{

}

void Renderer::resetProjection(Dim windowSize)
{
    ratio = windowSize.getRatioWH();

    // Matrix::frustum(proj, 0, -ratio * units, ratio * units, -units, units, -units, units);
    // Matrix::setLookAt(view, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    // apply();


    // for (int i = 0; i < 16; i++){
    //     mvp[i] = 0;
    // }
    // mvp[0] = 0.01f;
    // mvp[5] = 0.01f;
    // mvp[10] = -0.01f;
    // mvp[15] = 1.00f;

    // proj = new glm::mat4(glm::ortho(-ratio * units, ratio * units, -units, units, -units, units));
    // glm::mat4 ident = glm::mat4(1.0f);
    // glm::vec3 trvec = glm::vec3(0, 0, 0);
    // view = new glm::mat4(glm::translate(ident, trvec));
    // mvp = new glm::mat4((*proj * *view * glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))));

    std::cout << units << std::endl;

    Matrix::ortho(proj, 0, -ratio * units, ratio * units, -units, units, -units, units);
    float test[16] = {1.0f};
    Matrix::translate(test, 0, 0, 0, 0);
    printMatrix(test);
    //Matrix::translate(view, 0, 0, 0, 0);
    for (int i = 0; i < 16; i+=5){ view[i] = 1.0f; }
    Matrix::multiply(mvp, proj, test);
    //Matrix::multiply(mvp, test, view);
}

void Renderer::printMatrix(float matrix[])
{
    for (int i = 0; i < 4; i++)
    {
        std::cout
        << matrix[i*4] << "\t"
        << matrix[i*4+1] << "\t"
        << matrix[i*4+2] << "\t"
        << matrix[i*4+3] << "\t"
        << std::endl;
    }
}