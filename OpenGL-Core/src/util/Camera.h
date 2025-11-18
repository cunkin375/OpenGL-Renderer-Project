#pragma once

#include "core/Window.h"

#include <glad.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

// Transformation of coordinates into normalized device coordinates
// Pipeline:
// > Model Coordinates -> World Coordinates -> View Coordinates -> Clip Coordinates -> NDC -> Screen Coordinates


class Camera
{
public:
    void update();
    void transform(GLuint transformLoc);

    inline const glm::mat4 getProjection() { return m_Projection; }
    inline const glm::mat4 getView()       { return m_View; }

 private:
    glm::mat4 m_Projection {1.0f};
    glm::mat4 m_Model      {1.0f};
    glm::mat4 m_View       {1.0f};


};
