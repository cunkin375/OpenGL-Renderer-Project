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

    inline bool isWPressed(const Window& window)
    {
        return glfwGetInputMode(window.getHandle(), GLFW_KEY_W) == GLFW_PRESS;
    }

    inline bool isSPressed(const Window& window)
    {
        return glfwGetInputMode(window.getHandle(), GLFW_KEY_S) == GLFW_PRESS;
    }

    inline bool isAPressed(const Window& window)
    {
        return glfwGetInputMode(window.getHandle(), GLFW_KEY_A) == GLFW_PRESS;
    }

    inline bool isDPressed(const Window& window)
    {
        return glfwGetInputMode(window.getHandle(), GLFW_KEY_D) == GLFW_PRESS;
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
