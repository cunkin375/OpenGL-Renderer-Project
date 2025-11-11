workspace "Renderer Project"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "OpenGL-Core"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

   OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

   -- Include directories in OpenGL-Core
   IncludeDir = {}
   IncludeDir["GLFW"] = "vendor/GLFW/include"
   IncludeDir["glad"] = "vendor/glad/include"
   IncludeDir["KHR"]  = "vendor/KHR/include"
   IncludeDir["stb"]  = "vendor/stb/include"
   IncludeDir["glm"]  = "vendor/glm/include"

   include "OpenGL-Core/Build-Core.lua" 