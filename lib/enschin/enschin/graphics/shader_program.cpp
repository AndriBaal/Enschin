#include "shader_program.h"

unsigned int ShaderProgram::boundProgram = 0;

/**
 * @brief Read and compile the Shader from a vertex and fragment 
 * shader source. Load the shader in the memory.
 * 
 * @param vertexPath Path to the Vertex shader
 * @param fragmentPath Path to the fragment shader
 */
ShaderProgram::ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath)
    : shaderProgramId(0) {
    std::string vertexCode = getShaderCode(vertexPath);
    std::string fragmentCode = getShaderCode(fragmentPath);
    shaderProgramId = createShaderProgram(vertexCode, fragmentCode);

    glUseProgram(shaderProgramId);
}

/**
 * @brief Destroy the Shader Program object and delete the
 * Program from the GPU memory.
 */
ShaderProgram::~ShaderProgram() {
    glDeleteProgram(shaderProgramId);
}

/**
 * @brief Bind and use the shaderprogram.
 */
void ShaderProgram::bind() const {
    if (shaderProgramId != boundProgram){
        boundProgram = shaderProgramId;
        glUseProgram(shaderProgramId);
    } 
}

/**
 * @brief Unbind the shaderprogram.
 */
void ShaderProgram::unbind() const {
    glUseProgram(0);
}

/**
 * @brief Get the uniform location of a shader variable in
 * shader code.
 * 
 * @param name Name of the variable
 * @return int Returns the location id
 */
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

/**
 * @brief Get the shader code from a filee
 * 
 * @param shaderPath Path to the file
 * @return std::string Returns the shader code as a string
 */
std::string ShaderProgram::getShaderCode(const std::string& shaderPath) {
    std::ifstream stream(shaderPath);
    std::string line;
    std::stringstream ss;

    while (getline(stream, line)) {
        ss << line << '\n';
    }
    return ss.str();
}

/**
 * @brief Compile the given shader source code
 * 
 * @param type Type of the shader (fragment / vertex)
 * @param source Source code of the Shader
 * @return unsigned int Returns the id of the shader in the GPU
 */
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

/**
 * @brief Creates a Shaderprogram on the GPU 
 * @param vertexShader Vertex shader
 * @param fragmentShader Fragment Shader
 * @return unsigned int Shaderprogram id on the GPU
 */
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

/**
 * @brief Pass an int to the Shader
 * 
 * @param name Location id of the variable name in the shader
 * @param value Integer value
 */
void ShaderProgram::setUniform1i(const std::string& name, int value) {
    glUniform1i(getUniformLocation(name), value);
}

/**
 * @brief Pass a float to the shader
 * 
 * @param name Location id of the variable name in the shader
 * @param value Float value
 */
void ShaderProgram::setUniform1f(const std::string& name, float value) {
    glUniform1f(getUniformLocation(name), value);
}

/**
 * @brief Pass 4 Float to the shader
 * 
 * @param name Location id of the variable name in the shader
 * @param f0 value1
 * @param f1 value2
 * @param f2 value3
 * @param f3 value4
 */
void ShaderProgram::setUniform4f(const std::string& name, float f0, float f1, float f2, float f3) {
    glUniform4f(getUniformLocation(name), f0, f1, f2, f3);
}

/**
 * @brief Pass a color to the shader
 * 
 * @param name Location id of the variable name in the shader
 * @param color 
 */
void ShaderProgram::setColor(const std::string& name, const Color& color) {
    glUniform4f(getUniformLocation(name), color.r, color.g, color.b, color.a);
}

/**
 * @brief Pass a 4x4 Matrix to the shader
 * 
 * @param name Location id of the variable name in the shader
 * @param matrix 4x4 Matrix to pass
 */
void ShaderProgram::setUniformMat4f(const std::string& name, const float matrix[]) {
    glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0]);
}