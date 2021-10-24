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

}

void Renderer::translate(Vec2 pos)
{
    Matrix::translate(view, 0, pos.x, pos.y, 0);
    Matrix::multiply(mvp, view, proj);
}

void Renderer::rotate(float angle)
{
    // Matrix::rotate(view, 0, angle, 0.0f, 0.0f, 1.0f);
    // Matrix::multiply(mvp, view, proj);
    static bool test = true;

    float sTemp[16] = {0.0f};
    Matrix::setRotate(sTemp, 0, angle, 0.0f, 0.0f, -1.0f);
    Matrix::multiply(sTemp, sTemp, view);
    
    test=!test;
    for (int i = 0; i < 16; i++)
    {
        view[i] = sTemp[i];
    }

    Matrix::multiply(mvp, view, proj);
}

void Renderer::scale(Vec2 scaling)
{

}

void Renderer::resetProjection(Dim windowSize)
{
    ratio = windowSize.getRatioWH();
    Matrix::frustum(proj, 0, ratio, -ratio, -1.0f, 1.0f, 3.0f, 7.0f);
    resetMatrix();
}

void Renderer::resetMatrix()
{
    Matrix::setLookAt(view, 0.0f, 0.0f, 0.0f, -3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    Matrix::multiply(mvp, view, proj);

}

