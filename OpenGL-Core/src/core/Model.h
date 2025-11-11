 #pragma once

// VVV TEMP!!!! VVV
#include "D:\dev\Renderer Project - Premake\OpenGL-Core\assets\models\triangle.h"

#include "Mesh.h"
#include "Texture.h"

#include <vector>

class Model
{
public:
    Model() = default;
    Model(const char* path);

    void render();
    void remove();

private:
    std::vector<Mesh> m_Meshes;
    std::vector<Texture> m_Textures;


};
