#pragma once
#include "light.h"
#include "color.h"
#include "shader_program.h"
#include "render_model.h"
#include "texture.h"
#include "vec2.h"
#include "vec4.h"
#include "matrix.h"
#include "ray2.h"
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
    static ShaderProgram circleColorProgram;
    static ShaderProgram circleTextureProgram;

	float ratio;
	float fov;
public:
	Renderer() = default;
	Renderer(Vec2 windowSize, float units=5.0f);
    static void free();
	static void initShaderPrograms();

	void resetProjection(Vec2 windowDim);
	void resetMatrix();
    void setFov(float fov);
    float getFov() const{ return fov; }

    void translate (Vec2 pos);
	void rotate(float angle);
	void scale(Vec2 scaling);

	void translateAndRenderTexture(const RenderModel* model, const Texture* tex, Vec2 pos, float rotation=.0f);
	void renderColor(const RenderModel* model, const Color*) const;
	void renderTexture(const RenderModel* model, const Texture* texture) const;
	void renderColoredTexture(const RenderModel* model, const Texture* texture, const Color* color) const;
    void renderRainbow(const RenderModel* model, float totalTime) const;
    void renderCroppedTexture(const RenderModel* model, const Texture* tex, Vec4 textureCoordinates) const;
    void renderCircleColor(const RenderModel* model, const Color* color);
    void renderCircleTexture(const RenderModel* model, const Texture* texture);

	float getRatio() const{ return ratio; }

};

