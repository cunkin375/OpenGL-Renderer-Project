#pragma once

#include "Window.h"
#include "Model.h"
#include "util/Shader.h"
#include "util/Camera.h"

#include <glad.h>

class Renderer 
{
public:
	Renderer(const WindowProperties& windowProp);
	~Renderer();

	void render();

private:
	Shader m_Shader;
	Model  m_Model;
	Camera m_Camera;


};
