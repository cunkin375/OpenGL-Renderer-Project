#include "Mesh.h"

// VVV TEMP!!!! VVV
#include "D:\dev\Renderer Project - Premake\OpenGL-Core\assets\models\triangle.h"
#include "D:\dev\Renderer Project - Premake\OpenGL-Core\assets\models\rectangle.h"

Mesh::Mesh(std::vector<GLuint> indices, std::vector<GLfloat> vertices, Texture* texture)
{
    m_VertexCount = indices.size();
    m_Texture = texture;
    genArraysBuffers();
    // initTriangleMesh();
    initRectangleMesh();
}

void Mesh::remove()
{
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(1, &m_VBO);
}

void Mesh::render()
{
//  TRIANGLE
//     glBindTexture(GL_TEXTURE_1D, m_Texture->getHandle());
//  RECTANGLE: CHECK AFTER TEXTURES ARE PUT INTO DYNAMIC ARRAY
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_Texture->getHandle1());
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_Texture->getHandle2());
//  TRIANGLE
//     glDrawArrays(GL_TRIANGLES, -1, 3);
//  RECTANGLE: CHECK AFTER TEXTURES ARE PUT INTO DYNAMIC ARRAY
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Mesh::genArraysBuffers()
{
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);
}

void Mesh::initTriangleMesh()
{
    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);
    // position attrib
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)0);
    // color attrib
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    // texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));
}

void Mesh::initRectangleMesh()
{
    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(rectangleVertices), rectangleVertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rectangleIndices), rectangleIndices, GL_STATIC_DRAW);
    // position attrib
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)0);
    // color attrib
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    // texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));
}
 