#pragma once
#include "light.h"
#include "color.h"
#include "shader_program.h"
#include "model.h"
#include "texture.h"
#include "dim2.h"
#include "vec4.h"
#include "matrix.h"
#include "ray2.h"
#include "game_object.h"
#include "mouse.h"

/**
 * @brief Renderer for rendering out to the Screen. Holds projection
 * Matrices, Shaderprograms and functions to transform and render.
 */
class Renderer {
private:
	float proj[16];
	float view[16];
	float mvp[16];

	static ShaderProgram colorProgram;
	static ShaderProgram textureProgram;
	static ShaderProgram coloredTextureProgram;
	static ShaderProgram rainbowProgram;
    static ShaderProgram cropProgram;

	float ratio;
	float units;
public:
    static std::unordered_map<int, ShaderProgram> programs;
	Renderer() = default;
	Renderer(Dim2 windowSize, float units=50.0f);
	static void initShaderPrograms();
	void resetProjection(Dim2 windowDim);
	void resetMatrix();
	void translate(Vec2 pos);
	void rotate(float angle);
	void scale(Vec2 scaling);

	void translateAndRenderTexture(Model& model, Texture& tex, Vec2 pos, float rotation=.0f);
	void renderColor(Model& model, Color& color);
	void renderTexture(Model& model, Texture& texture);
	void renderColoredTexture(Model& model, Texture& texture, Color& color);
    void renderRainbow(Model& model, float totalTime);
    void renderCroppedTexture(Model& model, Texture& tex, Vec4 textureCoordinates);
	void renderRaytracing(Model& model, float vertices[], int amountOfVertices, Light& light, std::vector<GameObject> objects);

	float getRatio() { return ratio; }
	float getUnits() { return units; }
};

