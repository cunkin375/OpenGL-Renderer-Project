#pragma once

#include "Window.h"

class InputHandler
{
public:
	static bool isKeyPressed(Window& window, GLint key);
	static bool isKeyReleased(Window& window, GLint key);
	static bool isMBPressed(Window& window, GLint button);
	static bool isMBReleased(Window& window, GLint button);
	static void setMousePos(Window& window, GLdouble x, GLdouble y);
	static void disableMouse(Window& window);
	static void hideMouse(Window& window);
	static void showMouse(Window& window);
};
