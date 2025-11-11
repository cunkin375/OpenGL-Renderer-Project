#pragma once

#include <glad.h>

class Texture 
{
public:
    Texture();
    
    void remove();

    // HANDLE FUNCTIONS WILL CHANGE WHEN PROPERLY ITERATING THROUGH A DYNAMIC ARRAY
    inline GLuint getHandle1() const { return m_Handle1; }
    inline GLuint getHandle2() const { return m_Handle2; }
    inline GLint getWidth() const { return m_Width; }
    inline GLint getHeight() const { return m_Height; }

private:
    GLint  m_Width , m_Height;
    GLuint m_Handle1, m_Handle2;


};