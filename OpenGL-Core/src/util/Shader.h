#pragma once

#include <glad.h>
#include <string>

#include "glm.hpp"

class Shader
{
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    Shader() = default;

    std::string readShaderFile(const char* filepath);
    void remove();
    void use();
    void setInt(const std::string& name, GLint value) const;

    inline const GLuint getTransformLocation() { return m_TransformLocation; }

private:
    void checkCompileErrors(GLuint shader, std::string type);
    void startVertexShader(const char* vShaderCode);
    void startFragmentShader(const char* vFragmentCode);
    void startShaderProgram();

private:
    GLuint m_ProgramID;
    GLuint m_VertexShader, m_FragmentShader;
    GLuint m_TransformLocation;


};
