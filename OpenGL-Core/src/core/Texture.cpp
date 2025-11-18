#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <print>

Texture::Texture() // member values passed into constructor, remove lambda init once implimented
    : m_Width(0), m_Height(0), m_Handle1(0), m_Handle2(0)
{
    /* 
     * CODE SUCKS, TEXTURES SHOULD BE HANDLED THROUGH A DYNAMIC ARRAY
     * BUT I'M NOT THERE YET ):
     */
    GLint width, height, colorChannels; // passed into constructor
    stbi_set_flip_vertically_on_load(true);
    // Texture1
    glGenTextures(1, &m_Handle1);
    glBindTexture(GL_TEXTURE_2D, m_Handle1);
    // s and t refer to x and y coords
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // generate texture data
    unsigned char* data = stbi_load("assets/textures/container.jpg", &width, &height, &colorChannels, 0);
    if (!data) 
    { 
        std::println(stderr, "FAILED to load container texture data!");
    }
    // link texture to bound mesh using texture data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
    // Texture2
    glGenTextures(1, &m_Handle2);
    glBindTexture(GL_TEXTURE_2D, m_Handle2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // generate texture data
    data = stbi_load("assets/textures/awesomeface.png", &width, &height, &colorChannels, 0);
    if (!data)
    {
        std::println(stderr, "FAILED to load awesomeface texture data!");
    }
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
}

void Texture::remove()
{   // Check after integrating texture vector
    glDeleteTextures(1, &m_Handle1);
    glDeleteTextures(1, &m_Handle2);
}
