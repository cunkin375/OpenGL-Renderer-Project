#include "Model.h"

#include <glad.h>
#include <print>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

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
    std::vector<GLuint> indices   = { 3, 2, 1 };
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
    for (auto& mesh : m_Meshes)
        mesh.render();
}

void Model::remove()
{
    for (auto& mesh : m_Meshes)
    {
        mesh.remove();
    }
    for(auto& texture : m_Textures)
    {
        texture.remove();
    }
}