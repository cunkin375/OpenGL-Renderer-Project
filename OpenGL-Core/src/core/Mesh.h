#pragma once

#include "Texture.h"

#include <glad.h>
#include <vector>

class Mesh
{
public:
	Mesh(std::vector<GLuint> indices, std::vector<GLfloat> vertices, Texture* texture);

	void remove();
	void render();

private:
	void genArraysBuffers();
    void initCubeMesh();
	void initTriangleMesh();
	void initRectangleMesh();

private:
	size_t   m_VertexCount;
	Texture* m_Texture;
	GLuint   m_VAO, m_VBO, m_EBO;

};
