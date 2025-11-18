project "OpenGL-Core"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++latest"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files
   {
	   "src/**.h",
	   "src/**.cpp",
	   "vendor/**.h",
	   "vendor/**.hpp",
	   "vendor/**.c",
   -- temp for testing, remove later --
	   "assets/shaders/**.glsl",
	   "assets/models/**.h"
   }

   defines { "_CRT_SECURE_NO_WARNINGS" }

   includedirs 
   {
		"src",
		"assets",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.KHR}",
		"%{IncludeDir.stb}",
		"%{IncludeDir.glm}",
   }

   libdirs { "libs" }

   links
   {
	    "glfw3",
	    "opengl32",
   }

   targetdir ("../binaries/" .. OutputDir .. "/%{prj.name}")
   objdir    ("../binaries/intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
	   systemversion "latest"
	   defines { "GLCORE_PLATFORM_WINDOWS", "GLFW_INCLUDE_NONE" }

   filter "configurations:Debug"
	   defines { "DEBUG" }
	   runtime "Debug"
	   symbols "On"


   filter "configurations:Release"
	   defines { "RELEASE" }
	   runtime "Release"
	   optimize "On"
	   symbols "On"

   filter "configurations:Dist"
	   defines { "DIST" }
	   runtime "Release"
	   optimize "On"
	   symbols "Off"
