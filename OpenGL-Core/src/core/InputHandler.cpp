#include "InputHandler.h"

bool InputHandler::isKeyPressed(Window& window, GLint key)
{
	return glfwGetKey(window.getHandle(), key) == GLFW_PRESS;
}

bool InputHandler::isKeyReleased(Window& window, GLint key)
{
	return glfwGetKey(window.getHandle(), key) == GLFW_RELEASE;
}

bool InputHandler::isMBPressed(Window& window, GLint button)
{
	return glfwGetMouseButton(window.getHandle(), button) == GLFW_PRESS;
}

bool InputHandler::isMBReleased(Window& window, GLint button)
{
	return glfwGetMouseButton(window.getHandle(), button) == GLFW_RELEASE;
}

void InputHandler::setMousePos(Window& window, GLdouble xPos, GLdouble yPos)
{
	glfwSetCursorPos(window.getHandle(), xPos, yPos);
}

void InputHandler::disableMouse(Window& window)
{
	glfwSetInputMode(window.getHandle(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void InputHandler::hideMouse(Window& window)
{
	glfwSetInputMode(window.getHandle(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

void InputHandler::showMouse(Window& window)
{
	glfwSetInputMode(window.getHandle(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}