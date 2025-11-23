#pragma once

#include "core/Window.h"

#include <glad.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

// Transformation of coordinates into normalized device coordinates
// Pipeline:
// > Model Coordinates -> World Coordinates -> View Coordinates -> Clip Coordinates -> NDC -> Screen Coordinates
// > clipVertex = projectionMatrix * viewMatrix * localVertex


class Camera
{
    friend class CameraController;

    typedef struct CameraProperties 
    {
        float translationSpeed = 0.05f;

        glm::vec3 position { 0.0f, 0.0f, 3.0f };
        glm::vec3 target   { 0.0f,  0.0f,  0.0f };
        glm::vec3 up       { 0.0f,  1.0f,  0.0f };
        glm::vec3 front    { 0.0f,  1.0f, -1.0f };

        glm::mat4 view = glm::lookAt(position, target, up);
        glm::mat4 projection { 1.0f };
        glm::vec3 direction { glm::normalize(position - target) };

        glm::vec3 right { glm::normalize(glm::cross(up, direction)) };
        glm::vec3 actualUp { glm::cross(direction, right) };

    } Properties;

public:
    void update();
    void transform(GLuint programID);

 private:
    Properties m_CamProps;


};
