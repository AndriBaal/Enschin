#pragma once
#include "enschin/graphics/effects/light.hpp"
#include "enschin/graphics/effects/color.hpp"
#include "enschin/graphics/shader_program.h"
#include "enschin/graphics/model.h"
#include "enschin/graphics/texture.h"
#include "enschin/math/vec2.h"
#include "enschin/math/dim2.h"
#include "enschin/math/physics.h"
#include "enschin/math/matrix.h"
#include "enschin/math/ray2.hpp"
#include "enschin/objects/game_object.h"
#include "enschin/input/mouse.h"

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

	float ratio;
	float units;
public:
    static std::unordered_map<int, ShaderProgram> programs;
	Renderer() = default;
	Renderer(Dim2 windowSize, float units=1.0f);
	static void initShaderPrograms();
	void resetProjection(Dim2 windowDim);
	void resetMatrix();
	void translate(Vec2 pos);
	void rotate(float angle);
	void scale(Vec2 scaling);

	void translateAndRenderTexture(Model& model, Texture& tex, Vec2 pos, float rotation);
	void renderColor(Model& model, Color& color);
	void renderTexture(Model& model, Texture& texture);
	void renderColoredTexture(Model& model, Texture& texture, Color& color);
	void renderRaytracing(Model& model, float vertices[], int amountOfVertices, Light& light, std::vector<GameObject> objects);

	float getRatio() { return ratio; }
	float getUnits() { return units; }
};

