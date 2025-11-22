#include "Shader.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <print>
#include <cassert>

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
    assert(filepath != nullptr && "Shader file path cannot be null!");
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
        std::println(stderr, "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ");
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

void Shader::checkCompileErrors(GLuint shaderIndex, ShaderType typeEnum)
{
    constexpr size_t c_BufferSize = 1024;
    GLint  compileSuccess; // compile success cannot be a bool (C-based library)
    GLchar consoleLog[c_BufferSize];
    switch (typeEnum) 
    {
    case ShaderType::PROGRAM:
        glGetProgramiv(shaderIndex, GL_LINK_STATUS, &compileSuccess);
        if (!compileSuccess)
        {
            glGetProgramInfoLog(shaderIndex, c_BufferSize, NULL, consoleLog);
            std::println(stderr, "ERROR::PROGRAM_LINKING_ERROR::");
            std::println(stderr, "%s", consoleLog);
        }
        break;
    case ShaderType::COMPONENT:
        glGetShaderiv(shaderIndex, GL_COMPILE_STATUS, &compileSuccess);
        if (!compileSuccess)
        {
            glGetShaderInfoLog(shaderIndex, c_BufferSize, NULL, consoleLog);
            std::println(stderr, "ERROR::SHADER_COMPILATION_ERROR::");
            std::println(stderr, "%s", consoleLog);
        }
        break;
    default:
        std::println(stderr, "ERROR::UNKNOWN_SHADER_TYPE::");
    }
}

void Shader::startFragmentShader(const char* fShaderCode)
{
    m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m_FragmentShader, 1, &fShaderCode, NULL);
    glCompileShader(m_FragmentShader);
    checkCompileErrors(m_FragmentShader, ShaderType::COMPONENT);
}

void Shader::startShaderProgram()
{
    m_ProgramID = glCreateProgram();
    glAttachShader(m_ProgramID, m_VertexShader);
    glAttachShader(m_ProgramID, m_FragmentShader);
    glLinkProgram(m_ProgramID);
    checkCompileErrors(m_ProgramID, ShaderType::PROGRAM);
    // shader components must be deleted upon starting shader program
    glDeleteShader(m_VertexShader);
    glDeleteShader(m_FragmentShader);
}

void Shader::startVertexShader(const char* vShaderCode)
{
    m_VertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m_VertexShader, 1, &vShaderCode, NULL);
    glCompileShader(m_VertexShader);
    checkCompileErrors(m_VertexShader, ShaderType::COMPONENT);
}

void Shader::setInt(const std::string& name, size_t index)
{
    glUniform1i(glGetUniformLocation(m_ProgramID, name.c_str()), index);
}
