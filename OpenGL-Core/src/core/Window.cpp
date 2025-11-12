#include "Window.h"

#include <print>

Window::Window(WindowProperties& properties)
    : m_Handle(nullptr)
    , m_Properties(properties)
{  
   if (!glfwInit())  
   {  
       // TODO include logger macro to handle in util  
       std::println("GLFW couldn't start!");  
       return;  
   }
   // 7/22/25: OpenGL version 4.6  
   glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);  
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);  
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);  
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  
#ifdef __APPLE__
   glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  
#endif  
   GLFWmonitor* monitor = NULL;  
   const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());  
   if (properties.Fullscreen)  
   {  
       monitor = glfwGetPrimaryMonitor();
       properties.Width  = mode->width;
       properties.Height = mode->height;
       m_Properties = properties;  
   }
   m_Handle = glfwCreateWindow(properties.Width, properties.Height, properties.Title.c_str(), monitor, NULL);  
   if (!m_Handle)  
   {  
       std::println("Failed to create window!");  
       glfwDestroyWindow(m_Handle);  
       glfwTerminate();  
       return;  
   }
   glfwMakeContextCurrent(m_Handle);  
   if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))  
   {  
       std::println("Failed to load GLAD!");
       glfwDestroyWindow(m_Handle);  
       glfwTerminate();  
       return;  
   }
   glfwSetFramebufferSizeCallback(m_Handle, framebufferSizeCallback); // yells at you for using any uint  
   glViewport(0, 0, properties.Width, properties.Height);  
} // end Window constructor

Window::~Window()
{
    glfwDestroyWindow(m_Handle);
    glfwTerminate();
}

void Window::clear() 
{
    glClear(GL_COLOR_BUFFER_BIT);
} 

void Window::close()
{
    glfwSetWindowShouldClose(m_Handle, true);
}

bool Window::isOpen()
{
    return !glfwWindowShouldClose(m_Handle);
}

void Window::show()
{
    glfwShowWindow(m_Handle);
}

void Window::update()
{
    glfwPollEvents();
    glfwSwapBuffers(m_Handle);
}

void Window::framebufferSizeCallback(GLFWwindow* window, GLint width, GLint height)
{
    glViewport(0, 0, width, height);
}