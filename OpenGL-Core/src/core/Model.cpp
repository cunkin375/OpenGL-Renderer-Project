#include "Model.h"
#include "glfw3.h"

#include <glad.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <algorithm>

Model::Model(const char* path)
{    
    // Load model data from the specified path
    // For now, just create a default mesh

    //std::vector<GLuint> indices;
    //for (GLuint i : triangleIndices)
    //{
    //    indices.emplace_back(triangleIndices[i]);
    //}

    //std::vector<GLfloat> vertices;
    //for (size_t i = 0; i < sizeof(triangleVertices) / sizeof(triangleVertices[0]); ++i)  
    //{  
    //    vertices.emplace_back(triangleVertices[i]);  
    //}

    // NOTE: ONLY USED TO BE PASSED INTO MESH CONSTRUCTOR, NOT USED IN RENDERING MESH
    std::vector<GLuint>  indices  = { 3, 2, 1 };
    std::vector<GLfloat> vertices = { 3, 3, 5 };

    //std::println("Model created with {} indices", indices.size());
    //std::println("Model created with {} vertices", vertices.size());

    Texture* diffuseTexture = nullptr;
    m_Textures.emplace_back(Texture());  // allocate texture on the end of the vector
    diffuseTexture = &m_Textures.back(); // give address of Texture on end of vector

    m_Meshes.emplace_back(indices, vertices, diffuseTexture);
}

void Model::render()
{
	std::ranges::for_each(m_Meshes, [](auto& mesh) { mesh.render(); });
}

void Model::update()
{
    m_ModelMatrix = glm::mat4{1.0f};
    m_ModelMatrix = glm::rotate(m_ModelMatrix, (GLfloat)glfwGetTime() * glm::radians(50.0f), glm::vec3{0.5f, 1.0f, 0.0f});
}

void Model::transform(GLuint programID)
{
    GLuint modelMatrixLoc = glGetUniformLocation(programID, "model");
    glUniformMatrix4fv(modelMatrixLoc, 1, GL_FALSE, glm::value_ptr(m_ModelMatrix));
}

void Model::remove()
{
	std::ranges::for_each(m_Meshes,   [](auto& mesh)       { mesh.remove(); });
	std::ranges::for_each(m_Textures, [](auto& texture) { texture.remove(); });
}
