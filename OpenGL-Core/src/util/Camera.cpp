#include "Camera.h"
#include "core/Window.h"
#include <gtc/type_ptr.hpp>

void Camera::update()
{
    m_View  = glm::mat4{1.0f};
    m_Projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    m_View  = glm::translate(m_View, glm::vec3{0.0f, 0.0f, -3.0f});
}

void Camera::transform(GLuint shaderID)
{
    GLuint viewMatrixLoc = glGetUniformLocation(shaderID, "view");
    GLuint projectionMatrixLoc = glGetUniformLocation(shaderID, "projection");
    glUniformMatrix4fv(viewMatrixLoc, 1, GL_FALSE, glm::value_ptr(m_View));
    glUniformMatrix4fv(projectionMatrixLoc, 1, GL_FALSE, glm::value_ptr(m_Projection));
}
