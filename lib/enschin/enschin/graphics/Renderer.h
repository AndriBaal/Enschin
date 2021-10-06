#pragma once
#include <gtc/matrix_transform.hpp>
#include <glm.hpp>
#include <enschin/graphics/Color.hpp>
#include "../GameHandler.h"
#include "../Window.h"
#include "Texture.h"
#include "ShaderProgram.h"
#include "../math/Vectors.h"
#include "Model.h"

class Window;
class Renderer
{
private:
	glm::mat4* proj;
	glm::mat4* view;
	glm::mat4* mvp;

	ShaderProgram* colorProgram;
	ShaderProgram* textureProgram;
	ShaderProgram* coloredTextureProgram;

	void apply();
public:
	Renderer();
	void init(Window* window);
	void resetProjection(Window* window);
	void translate(Vector2 pos);
	void rotate(float angle);
	void scale(Vector2 scaling);
	/*void applyMatrixChange();
	void resetMatrix();*/

	void renderColor(Model& model, const Color& color);
	void renderTexture(Model& model, Texture& texture);
	void renderColoredTexture(Model& model, Texture& texture, const Color& color);
};

