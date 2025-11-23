#include "CameraController.h"
#include "core/InputHandler.h"

#include <cassert>


CameraController::CameraController(Window& window, Camera::Properties& props)
    : m_Window(window), m_CamProps(props)
{
}

void CameraController::processInput()
{
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    m_CamProps.translationSpeed = 2.5f * deltaTime;

    if (InputHandler::isWPressed(m_Window))
    {
        m_CamProps.position -= m_CamProps.translationSpeed * m_CamProps.direction;
    }
    else if (InputHandler::isSPressed(m_Window))
    {
        m_CamProps.position += m_CamProps.translationSpeed * m_CamProps.direction;
    }
    if (InputHandler::isAPressed(m_Window))
    {
        m_CamProps.position -= glm::normalize(glm::cross(m_CamProps.up, m_CamProps.direction)) * m_CamProps.translationSpeed;
    }
    else if (InputHandler::isDPressed(m_Window))
    {
        m_CamProps.position += glm::normalize(glm::cross(m_CamProps.up, m_CamProps.direction)) * m_CamProps.translationSpeed;
    }
}
