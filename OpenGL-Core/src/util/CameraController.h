#pragma once

#include "Camera.h"
#include "core/Window.h"

class CameraController
{
public:
    CameraController(Window& window, Camera::Properties& camProps);

    void processInput();

private:
    Window& m_Window;
    Camera::Properties& m_CamProps;

};
