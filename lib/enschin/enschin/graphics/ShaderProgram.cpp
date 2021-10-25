#include "ShaderProgram.h"


ShaderProgram::ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath)
    : shaderProgramId(0) {
    std::string vertexCode = getShaderCode(vertexPath);
    std::string fragmentCode = getShaderCode(fragmentPath);
    shaderProgramId = createShaderProgram(vertexCode, fragmentCode);

    glUseProgram(shaderProgramId);
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(shaderProgramId);
}

void ShaderProgram::bind() const {
    glUseProgram(shaderProgramId);
}

void ShaderProgram::unbind() const {
    glUseProgram(0);
}

int ShaderProgram::getUniformLocation(const std::string& name) {
    if (uniformLocationCache.find(name) != uniformLocationCache.end())
        return uniformLocationCache[name];

    int location = glGetUniformLocation(shaderProgramId, name.c_str());
    if (location == -1)
        std::cout << "No active uniform variable with name " << name << " found" << std::endl;

    uniformLocationCache[name] = location;

    return location;
}

enum ShaderType {
    NONE = -1, VERTEX = 0, FRAGMENT = 1
};

std::string ShaderProgram::getShaderCode(const std::string& shaderPath) {
    std::ifstream stream(shaderPath);
    std::string line;
    std::stringstream ss;

    while (getline(stream, line)) {
        ss << line << '\n';
    }
    return ss.str();
}

unsigned int ShaderProgram::compileShader(unsigned int type, const std::string& source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    // Error handling
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    //std::cout << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader compile status: " << result << std::endl;
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout
            << "Failed to compile "
            << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
            << "shader"
            << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }
    return id;
}

unsigned int ShaderProgram::createShaderProgram(const std::string& vertexShader, const std::string& fragmentShader) {
    // create a shader program
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);

    GLint program_linked;

    glGetProgramiv(program, GL_LINK_STATUS, &program_linked);
    if (program_linked != GL_TRUE) {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetProgramInfoLog(program, 1024, &log_length, message);
        std::cout << "Failed to link program" << std::endl;
        std::cout << message << std::endl;
    }

    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

void ShaderProgram::setUniform1i(const std::string& name, int value) {
    glUniform1i(getUniformLocation(name), value);
}

void ShaderProgram::setUniform1f(const std::string& name, float value) {
    glUniform1f(getUniformLocation(name), value);
}

void ShaderProgram::setUniform4f(const std::string& name, float f0, float f1, float f2, float f3) {
    glUniform4f(getUniformLocation(name), f0, f1, f2, f3);
}

void ShaderProgram::setColor(const std::string& name, const Color& color) {
    glUniform4f(getUniformLocation(name), color.r, color.g, color.b, color.a);
}

void ShaderProgram::setUniformMat4f(const std::string& name, const float matrix[]) {
    glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0]);
}