#pragma once

#include <glad.h>
#include <glfw3.h>
#include <string>

struct WindowProperties
{
    std::string Title;
    bool        Fullscreen;
    GLuint		Width, Height;

    WindowProperties(const std::string& title = "Project Window",
                     bool   fullscreen = false,
                     GLuint width  = 800,
                     GLuint height = 600) 
                  : Title(title), Fullscreen(fullscreen), Width(width), Height(height)
    {
    }

};

class Window  
{  
public:
    Window() = default;

    Window(WindowProperties& properties);
   ~Window();   

   bool isOpen();
   void clear();
   void close();
   void show();
   void update();

   inline WindowProperties& getWindowInfo() { return m_Properties; }
   inline GLFWwindow* getHandle() const { return m_Handle; }

private:  
   static void framebufferSizeCallback(GLFWwindow* m_Handle, GLint width, GLint height);  

private:  
   GLFWwindow*		m_Handle;
   WindowProperties m_Properties;


};