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
	static float proj[16];
	static float view[16];
	static float mvp[16];

	static ShaderProgram* colorProgram;
	static ShaderProgram* textureProgram;
	static ShaderProgram* coloredTextureProgram;

	static void initShaderPrograms();
	static float ratio;
	static float units;
public:
	static void init(Dim2 windowSize, float units=1);
	static void resetProjection(Dim2 windowDim);
	static void resetMatrix();
	static void absoluteTranslate(Vec2 pos);
	static void translate(Vec2 pos);
	static void rotate(float angle);
	static void scale(Vec2 scaling);

	static void translateAndRenderTexture(Model& model, Texture& tex, Vec2 pos);
	static void renderColor(Model& model, Color& color);
	static void renderTexture(Model& model, Texture& texture);
	static void renderColoredTexture(Model& model, Texture& texture, Color& color);
	static void renderRaytracing(Model& model, float vertices[], int amountOfVertices, Light& light, std::vector<GameObject> objects);

	static float getRatio() { return ratio; }
	static float getUnits() { return units; }
};

