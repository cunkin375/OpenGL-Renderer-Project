#pragma once

#include "Window.h"
#include "Model.h"
#include "util/Shader.h"
#include "util/Camera.h"

#include <glad.h>
#include <memory>

class Renderer 
{
public:
	Renderer(const WindowProperties& windowProp);
	~Renderer();

	void render();

private:
	Model  m_Model;
	Shader m_Shader;
	Camera m_Camera;


};