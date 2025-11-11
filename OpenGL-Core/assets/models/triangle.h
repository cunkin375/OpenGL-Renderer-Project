#include <glad.h>
#pragma once  

inline GLfloat triangleVertices[] =
{
	// positions		// colors			// texture coords
	 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,
	-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,	 1.0f, 0.0f,
	 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,	 0.5f, 1.0f
};
inline GLfloat triangleBorderColor[] = 
{ 
	1.0f, 1.0f, 0.0f, 1.0f 
};
inline GLuint triangleIndices[] = 
{
    0, 1, 2
};