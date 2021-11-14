#include "renderer.h"

ShaderProgram Renderer::colorProgram;
ShaderProgram Renderer::textureProgram;
ShaderProgram Renderer::coloredTextureProgram;
ShaderProgram Renderer::rainbowProgram;

/**
 * @brief Create a new Renderer with its own projection matrices.
 * 
 * @param windowSize WindowSize for the matrices
 * @param units Units from the Center to the Top/Bottom of the Screen
 */
Renderer::Renderer(Dim2 windowSize, float units) : units(units) {
    resetProjection(windowSize);
    resetMatrix();
}

/**
 * @brief Initialize the shaderPrograms
 */
void Renderer::initShaderPrograms() {
    colorProgram = ShaderProgram("./enschin/shader/vertex.vert", "./enschin/shader/color.frag");
    textureProgram = ShaderProgram("./enschin/shader/vertex.vert", "./enschin/shader/texture.frag");
    coloredTextureProgram = ShaderProgram("./enschin/shader/vertex.vert", "./enschin/shader/colored_texture.frag");
    rainbowProgram = ShaderProgram("./enschin/shader/vertex.vert", "./enschin/shader/rainbow.frag");
}

/**
 * @brief Render a model in a set Color
 * 
 * @param model Model to render
 * @param color Color & opacity of the paint
 */
void Renderer::renderColor(Model& model, Color& color) {
    model.bind();
    colorProgram.bind();
    colorProgram.setUniformMat4f("u_MVP", mvp);
    colorProgram.setColor("u_Color", color);

    glDrawElements(GL_TRIANGLES, model.getAmountOfIndices(), GL_UNSIGNED_INT, nullptr);
}

/**
 * @brief Render a texture on a model.
 * 
 * @param model Model to render
 * @param texture Texture to render
 */
void Renderer::renderTexture(Model& model, Texture& texture) {
    model.bind();
    texture.bind(); 
    textureProgram.bind();
    textureProgram.setUniform1i("u_Texture", 0);
    textureProgram.setUniformMat4f("u_MVP", mvp);

    glDrawElements(GL_TRIANGLES, model.getAmountOfIndices(), GL_UNSIGNED_INT, nullptr);
}

/**
 * @brief Render a texture on a model with a given
 * texture on top of it. The alpha value of the color
 * defines the opacity.
 * 
 * @param model Model to render
 * @param texture Texture to render
 * @param color Color to paint the texture with
 */
void Renderer::renderColoredTexture(Model& model, Texture& texture, Color& color) {
    model.bind();
    texture.bind(); 
    coloredTextureProgram.bind();
    coloredTextureProgram.setUniform1i("u_Texture", 0);
    coloredTextureProgram.setUniformMat4f("u_MVP", mvp);
    coloredTextureProgram.setColor("u_Color", color);
    glDrawElements(GL_TRIANGLES, model.getAmountOfIndices(), GL_UNSIGNED_INT, nullptr);
}

/**
 * @brief Render an animated rainbow pattern on top of the model
 *
 * @param model Model to render
 */
void Renderer::renderRainbow(Model &model, float totalTime) {
    model.bind();
    rainbowProgram.bind();
    rainbowProgram.setUniformMat4f("u_MVP", mvp);
    rainbowProgram.setUniform1f("u_TotalTime", totalTime);
    glDrawElements(GL_TRIANGLES, model.getAmountOfIndices(), GL_UNSIGNED_INT, nullptr);
}

// DO Documentation
void Renderer::renderRaytracing(Model& model, float vertices[], int amountOfVertices, Light& light, std::vector<GameObject> objects) {
    std::vector<Ray2> intersectingLines = std::vector<Ray2>();
    for(std::vector<GameObject>::iterator it = objects.begin(); it != objects.end(); it++) {
        for(int i = 0; i < amountOfVertices; i++) {
            // if (Physics::isLineIntersecting(it., )
            // {
            // }
        }
    }
}


// Matrix operations

/**
 * @brief Translate, render a texture on a certain model and translate back.
 * 
 * @param model Model to render
 * @param tex Texture to render
 * @param pos Position to translate to
 */
void Renderer::translateAndRenderTexture(Model& model, Texture& tex, Vec2 pos, float rotation){
    translate(pos);
    rotate(rotation);
    renderTexture(model, tex);
    rotate(-rotation);
    translate(-pos);
}

/**
 * @brief Translate the matrix to a specific position. The translation
 * always translates from the last position, so you have to translate
 * back after rendering.
 * 
 * @param pos Position to translate to
 */
void Renderer::translate(Vec2 pos) {
    Matrix::translate(view, pos);
    Matrix::multiply(mvp, view, proj);
}

/**
 * @brief Rotate the matrix by an angle in degree.
 * The rotation always rotates from the last rotation, so you have to
 * rotate back after rendering.
 * 
 * @param angle Rotation angle in degree
 */
void Renderer::rotate(float angle) {
    Matrix::rotate(view, angle);
    Matrix::multiply(mvp, view, proj);
}

/**
 * @brief Scale the Matrix and the outgoing result
 * 
 * @param scaling Scale factor on x and y axis
 */
void Renderer::scale(Vec2 scaling) {

}


/**
 * @brief Reset the entire Projection
 * Used on start or when the screen size has changed.
 * 
 * @param windowSize New Size of the window
 */
void Renderer::resetProjection(Dim2 windowSize) {
    ratio = windowSize.getRatioWH();
    Matrix::frustum(proj, ratio, -ratio, -1, 1, 3.0f, 7.0f);
}

/**
 * @brief Reset the matrices to look at 0
 * Everything in the matrix get restored (0 rotation, 0 translation, 0 scaling).
 */
void Renderer::resetMatrix() {
    Matrix::setLookAt(view, {0.0f, 0.0f, -3.0f}, {}, {0.0f, 1.0f, 0.0f});
    Matrix::multiply(mvp, view, proj);
}

