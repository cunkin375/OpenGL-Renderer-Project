#include "Shader.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <print>

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
    std::string vertexCode   = readShaderFile(vertexPath);
    std::string fragmentCode = readShaderFile(fragmentPath);
    startVertexShader(vertexCode.c_str());
    startFragmentShader(fragmentCode.c_str());
    startShaderProgram();
}

std::string Shader::readShaderFile(const char* filepath)
{
    std::string       shaderCode;
    std::ifstream     shaderFile;
    std::stringstream shaderStream;
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        shaderFile.open(filepath);
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
        shaderCode = shaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::println("ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ");
    }
    return shaderCode;
}

void Shader::remove()
{
    glDeleteProgram(m_ProgramID);
}

void Shader::use()
{
    glUseProgram(m_ProgramID);
}

void Shader::checkCompileErrors(GLuint shader, std::string type)
{
    GLint  compileSuccess; // compile success cannot be a bool (C-based library)
    GLchar consoleLog[1024];
    if (type == "PROGRAM")
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &compileSuccess);
        if (!compileSuccess)
        {
            glGetProgramInfoLog(shader, 1024, NULL, consoleLog);
            std::println("ERROR::PROGRAM_LINKING_ERROR::");
            std::println("%s", consoleLog);
        }
    }
    else // type == Some Component 
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compileSuccess);
        if (!compileSuccess)
        {
            glGetShaderInfoLog(shader, 1024, NULL, consoleLog);
            std::println("ERROR::SHADER_COMPILATION_ERROR::");
            std::println("%s", consoleLog);
        }
    }
}

void Shader::startFragmentShader(const char* fShaderCode)
{
    m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m_FragmentShader, 1, &fShaderCode, NULL);
    glCompileShader(m_FragmentShader);
    checkCompileErrors(m_FragmentShader, "FRAGMENT");
}

void Shader::startShaderProgram()
{
    m_ProgramID = glCreateProgram();
    glAttachShader(m_ProgramID, m_VertexShader);
    glAttachShader(m_ProgramID, m_FragmentShader);
    glLinkProgram(m_ProgramID);
    checkCompileErrors(m_ProgramID, "PROGRAM");
    // shader components must be deleted upon starting shader program
    glDeleteShader(m_VertexShader);
    glDeleteShader(m_FragmentShader);
}

void Shader::startVertexShader(const char* vShaderCode)
{
    m_VertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m_VertexShader, 1, &vShaderCode, NULL);
    glCompileShader(m_VertexShader);
    checkCompileErrors(m_VertexShader, "VERTEX");
}

void Shader::setInt(const std::string& name, GLint value) const
{
    glUniform1i(glGetUniformLocation(m_ProgramID, name.c_str()), value);
}
