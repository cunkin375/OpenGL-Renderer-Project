#pragma once

#include <glad.h>
#include <string>

class Shader
{
    using ProgramIndex   = size_t;
    using ComponentIndex = size_t;

    enum class ShaderType : GLuint
    {
        PROGRAM = 0,
        COMPONENT
    };

public:
    Shader(const char* vertexPath, const char* fragmentPath);
    Shader() = default;

    std::string readShaderFile(const char* filepath);
    void remove();
    void use();
    void setInt(const std::string& name, size_t index);

    inline const GLuint getShaderProgram() { return m_ProgramID; }

private:
    void checkCompileErrors(size_t shaderIndex, ShaderType typeEnum);
    void startVertexShader(const char* vShaderCode);
    void startFragmentShader(const char* vFragmentCode);
    void startShaderProgram();

private:
    ProgramIndex   m_ProgramID;
    ComponentIndex m_VertexShader, m_FragmentShader;


};
