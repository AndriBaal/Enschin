#pragma once
#include <gtc/matrix_transform.hpp>
#include <glm.hpp>
#include <enschin/graphics/Color.hpp>
#include "Texture.h"
#include "../input/Mouse.h"
#include "ShaderProgram.h"
#include "../math/Vectors.h"
#include "../math/Dimension.h"
#include "Model.h"
#include "Light.h"
#include "../objects/GameObject.h"

class Renderer
{
private:
	static glm::mat4* proj;
	static glm::mat4* view;
	static glm::mat4* mvp;

	static ShaderProgram* colorProgram;
	static ShaderProgram* textureProgram;
	static ShaderProgram* coloredTextureProgram;

	static void apply();
	static void initShaderPrograms();
	static float ratio;
	static float units;
public:
	static void init(Dimension windowSize, float units=100);
	static void resetProjection(Dimension& windowSize);
	static void absoluteTranslate(Vector2 pos);
	static void translate(Vector2 pos);
	static void rotate(float angle);
	static void scale(Vector2 scaling);
	/*void applyMatrixChange();
	void resetMatrix();*/
	static void renderColor(Model& model, Color& color);
	static void renderTexture(Model& model, Texture& texture);
	static void renderColoredTexture(Model& model, Texture& texture, Color& color);
	static void renderRaytracing(Model& model, Light& light, std::vector<GameObject> objects);

	static float getRatio(){ return ratio; }
	static float getUnits(){ return units; }
};

