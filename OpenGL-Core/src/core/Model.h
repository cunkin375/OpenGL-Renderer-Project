#pragma once

#include "models/triangle.h"
#include "models/rectangle.h"

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
