#pragma once

#include "Mesh.h"
#include "Texture.h"
#include <glm.hpp>

#include <vector>

class Model
{
public:
    Model() = default;
    Model(const char* path);

    void render();
    void update();
    void transform(GLuint programID);
    void remove();

private:
    std::vector<Mesh> m_Meshes;
    std::vector<Texture> m_Textures;
    glm::mat4 m_ModelMatrix {1.0f};


};
