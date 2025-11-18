#pragma once

#include "Window.h"

namespace InputHandler
{
    inline bool isKeyPressed(const Window& window, GLint key)
    {
        return glfwGetKey(window.getHandle(), key) == GLFW_PRESS;
    }

    inline bool isKeyReleased(const Window& window, GLint key)
    {
        return glfwGetKey(window.getHandle(), key) == GLFW_RELEASE;
    }

    inline bool isMBPressed(const Window& window, GLint button)
    {
        return glfwGetMouseButton(window.getHandle(), button) == GLFW_PRESS;
    }

    inline bool isMBReleased(const Window& window, GLint button)
    {
        return glfwGetMouseButton(window.getHandle(), button) == GLFW_RELEASE;
    }

    inline void setMousePos(const Window& window, GLdouble xPos, GLdouble yPos)
    {
        glfwSetCursorPos(window.getHandle(), xPos, yPos);
    }

    inline void disableMouse(const Window& window)
    {
        glfwSetInputMode(window.getHandle(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }

    inline void hideMouse(const Window& window)
    {
        glfwSetInputMode(window.getHandle(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    }

    inline void showMouse(const Window& window)
    {
        glfwSetInputMode(window.getHandle(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
};
