#pragma once
#include <enschin/graphics/Color.hpp>
#include "../math/Vec2.h"
#include "../math/Dim.h"
#include "../math/Physics.h"
#include "../math/Matrix.h"
#include "../math/Ray.hpp"
#include "../objects/GameObject.h"
#include "../input/Mouse.h"
#include "ShaderProgram.h"
#include "Model.h"
#include "Light.hpp"
#include "Texture.h"

class Renderer
{
private:
	// static glm::mat4* proj;
	// static glm::mat4* view;
	// static glm::mat4* mvp;

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
	static void init(Dim windowSize, float units=1);
	static void resetProjection(Dim windowDim);
	static void resetMatrix();
	static void absoluteTranslate(Vec2 pos);
	static void translate(Vec2 pos);
	static void rotate(float angle);
	static void scale(Vec2 scaling);

	static void renderColor(Model& model, Color& color);
	static void renderTexture(Model& model, Texture& texture);
	static void renderColoredTexture(Model& model, Texture& texture, Color& color);
	static void renderRaytracing(Model& model, float vertices[], int amountOfVertices, Light& light, std::vector<GameObject> objects);

	static float getRatio(){ return ratio; }
	static float getUnits(){ return units; }
};

