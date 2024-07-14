workspace "Saber"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Saber/vendor/glfw/include"
IncludeDir["Glad"] = "Saber/vendor/Glad/include"
IncludeDir["ImGui"] = "Saber/vendor/imgui"
IncludeDir["glm"] = "Saber/vendor/glm"

include "Saber/vendor/glfw"
include "Saber/vendor/Glad"
include "Saber/vendor/imgui"

project "Saber"
    location "Saber"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
	staticruntime "on"

    targetdir ("bin/" ..outputdir.. "/%{prj.name}")
    objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    pchheader "sbpch.h"
	pchsource "Saber/src/sbpch.cpp"

    files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

    defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

    includedirs
	{
        "%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

    links 
	{ 
		"GLFW",
        "Glad",
        "ImGui",
		"opengl32.lib"
	}

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "SABER_BUILD_DLL",
            "SABER_PLATFORM_WINDOWS",
            "GLFW_INCLUDE_NONE"
        }


    filter "configurations:Debug"
        defines "SB_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "SB_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "SB_DIST"
        runtime "Release"
        optimize "on"


project "SandBox"
    location "SandBox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
	staticruntime "on"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp"
    }

    includedirs
    {
        "%{wks.location}/Saber/vendor/spdlog/include",
        "%{wks.location}/Saber/src",
        "%{wks.location}/Saber/vendor",
        "%{IncludeDir.glm}"
    }

    links
    {
        "Saber"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "SABER_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "SB_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "SB_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "SB_DIST"
        runtime "Release"
        optimize "on"