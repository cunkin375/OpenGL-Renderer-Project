#pragma once

#include "Window.h"
#include "Renderer.h"

#include <memory>

class Application
{
public:
    Application();

    void run();

private:
    void update();

private:
    std::unique_ptr<Window>   m_Window;
    std::unique_ptr<Renderer> m_Renderer;


};
