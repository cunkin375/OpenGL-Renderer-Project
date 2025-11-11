#pragma once

#include "core/Window.h"

#include <glad.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

class Camera
{
public:
    void update();
    void transform(GLuint transformLoc);

    inline const glm::mat4 getProjection() { return m_Projection; }
    inline const glm::mat4 getView() { return m_View; }

private:
    glm::mat4 m_Projection = glm::mat4(1.0f);
    glm::mat4 m_View = glm::mat4(1.0f);


};