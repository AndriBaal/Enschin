#pragma once

#include <string>
#include <unordered_map>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <malloc.h>
#include <GL/glew.h>
#include <string>
#include "enschin/graphics/effects/color.hpp"

/**
 * @brief With a shaderprogram you can load your
 *  shaders and pass the required Information to the Shader.
 */
class ShaderProgram {
private:
    unsigned int shaderProgramId;
    static unsigned int boundProgram;
    std::unordered_map<std::string, int> uniformLocationCache;

public:
    ShaderProgram() = default;
    ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath);
    ~ShaderProgram();
    void bind() const;
    void unbind() const;

    // Set uniforms
    void setUniform1i(const std::string& name, int value);
    void setUniform1f(const std::string& name, float value);
    void setUniform4f(const std::string& name, float f0, float f1, float f2, float f3);
    void setColor(const std::string& name, const Color& color);
    void setUniformMat4f(const std::string& name, const float matrix[]);

private:
    int getUniformLocation(const std::string& name);
    std::string getShaderCode(const std::string& shaderPath);
    unsigned int compileShader(unsigned int type, const std::string& source);
    unsigned int createShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);

};