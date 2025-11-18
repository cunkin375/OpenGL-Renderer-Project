#include "Application.h"
#include "InputHandler.h"

Application::Application() 
{
    WindowProperties properties{};
    m_Window = std::make_unique<Window>(properties);
    m_Renderer = std::make_unique<Renderer>(properties);
}

void Application::run() 
{
    m_Window->show();
    while (m_Window->isOpen()) 
    {
        m_Window->clear();
        m_Renderer->render();
        update();
    }
}

void Application::update() 
{
    m_Window->update();
    if (InputHandler::isKeyPressed(*m_Window, GLFW_KEY_ESCAPE)) 
    { 
        m_Window->close(); 
    }
}
