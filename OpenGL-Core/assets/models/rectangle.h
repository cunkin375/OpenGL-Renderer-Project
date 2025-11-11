#pragma once

#include <glad.h>

inline GLfloat rectangleVertices[] = 
{	// positions		// colors			// texture coords
	 0.5f,  0.5f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,
	 0.5f, -0.5f, 0.0f,	 0.0f, 1.0f, 0.0f,	 1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f,	 0.0f, 0.0f, 1.0f,	 0.0f, 0.0f,
	-0.5f,  0.5f, 0.0f,	 1.0f, 1.0f, 0.0f,	 0.0f, 1.0f
};
inline GLuint rectangleIndices[] =	
{											// indices start from 0
	0, 1, 3,								// first triangle
	1, 2, 3									// second triangle
};