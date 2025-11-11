#include "Camera.h"
#include <gtc/type_ptr.hpp>

void Camera::update()
{
    m_View = glm::mat4(1.0f);
    m_View = glm::translate(m_View, glm::vec3(0.5f, -0.5f, 0.0f));
    m_View = glm::rotate(m_View, (GLfloat)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
}

void Camera::transform(GLuint transformLoc)
{
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(m_View));
}
