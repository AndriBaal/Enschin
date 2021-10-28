#pragma once
#include "enschin/graphics/effects/Color.hpp"
#include "enschin/graphics/ShaderProgram.h"
#include "enschin/graphics/Model.h"
#include "enschin/graphics/effects/Light.hpp"
#include "enschin/graphics/Texture.h"
#include "enschin/math/Vec2.h"
#include "enschin/math/Dim2.h"
#include "enschin/math/Physics.h"
#include "enschin/math/Matrix.h"
#include "enschin/math/Ray2.hpp"
#include "enschin/objects/GameObject.h"
#include "enschin/input/Mouse.h"

/**
 * @brief Renderer for rendering out to the Screen. Holds projection
 * Matrices, Shaderprograms and functions to transform and render.
 */
class Renderer {
private:
	float proj[16];
	float view[16];
	float mvp[16];

	static ShaderProgram* colorProgram;
	static ShaderProgram* textureProgram;
	static ShaderProgram* coloredTextureProgram;

	float ratio;
	float units;
public:
	Renderer() = default;
	Renderer(Dim2 windowSize, float units=1.0f);
	static void initShaderPrograms();
	void resetProjection(Dim2 windowDim);
	void resetMatrix();
	void absoluteTranslate(Vec2 pos);
	void translate(Vec2 pos);
	void rotate(float angle);
	void scale(Vec2 scaling);

	void translateAndRenderTexture(Model& model, Texture& tex, Vec2 pos);
	void renderColor(Model& model, Color& color);
	void renderTexture(Model& model, Texture& texture);
	void renderColoredTexture(Model& model, Texture& texture, Color& color);
	void renderRaytracing(Model& model, float vertices[], int amountOfVertices, Light& light, std::vector<GameObject> objects);

	float getRatio() { return ratio; }
	float getUnits() { return units; }
};

