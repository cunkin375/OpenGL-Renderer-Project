#include "Camera.h"
#include <gtc/type_ptr.hpp>

void Camera::update()
{
    m_Model = glm::mat4(1.0f);
    m_Model = glm::rotate(m_Model, (GLfloat)glfwGetTime(), glm::vec3{1.0f, 1.0f, 1.0f});
}

void Camera::transform(GLuint transformLoc)
{
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(m_Model));
}
