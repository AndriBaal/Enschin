#pragma once
#include <gtc/matrix_transform.hpp>
#include <glm.hpp>
#include "../Window.h"
#include "Texture.h"
#include "ShaderProgram.h"
#include "../math/Vectors.h"
#include "Model.h"
#include "../GameHandler.h"

#include <iostream>


class Renderer
{
private:
	static glm::mat4* proj;
	static glm::mat4* view;
	static glm::mat4* mvp;

	static ShaderProgram* colorProgram;

	static void apply();
public:
	static void init(Window* window);
	static void resetProjection(Window* window);
	static void translate(Vector2 pos);
	static void rotate(float angle);
	static void scale(Vector2 scaling);
	/*static void applyMatrixChange();
	static void resetMatrix();*/

	static void renderTest(Model& m, Texture& t);
};

