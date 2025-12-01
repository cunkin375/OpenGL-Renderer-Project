#include "Camera.h"
#include <glfw3.h>
#include <gtc/type_ptr.hpp>

void Camera::update()
{
    m_CamProps.projection = glm::mat4{1.0f};
    m_CamProps.projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    constexpr float radius = 10.0f;
    float camX = sin(glfwGetTime()) * radius;
    float camZ = cos(glfwGetTime()) * radius;
    m_CamProps.position = glm::vec3{camX, 0.0f, camZ};
    m_CamProps.view = glm::lookAt(m_CamProps.position, m_CamProps.target, m_CamProps.up);
}

void Camera::transform(GLuint shaderID)
{
    GLuint viewMatrixLoc = glGetUniformLocation(shaderID, "view");
    GLuint projectionMatrixLoc = glGetUniformLocation(shaderID, "projection");
    glUniformMatrix4fv(viewMatrixLoc, 1, GL_FALSE, glm::value_ptr(m_CamProps.view));
    glUniformMatrix4fv(projectionMatrixLoc, 1, GL_FALSE, glm::value_ptr(m_CamProps.projection));
}
