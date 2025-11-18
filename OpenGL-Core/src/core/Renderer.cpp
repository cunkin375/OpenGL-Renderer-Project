#include "Renderer.h"
#include "util/Camera.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

Renderer::Renderer(const WindowProperties& windowProp)
    : m_Shader("assets/shaders/460.shader_vertex.glsl", "assets/shaders/460.shader_fragment.glsl")
    , m_Model("test")
{
    m_Shader.use();
    m_Shader.setInt("texture1", 0);
    m_Shader.setInt("texture2", 1);
}

Renderer::~Renderer()
{
    m_Shader.remove();
    m_Model.remove();
}

void Renderer::render()
{
    m_Shader.use();
    m_Camera.update();
    m_Model.update();
    m_Camera.transform(m_Shader.getShaderProgram());
    m_Model.transform(m_Shader.getShaderProgram());
    m_Model.render();
}
