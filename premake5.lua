workspace "Saber"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Saber"
    location "Saber"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" ..outputdir.. "/%{prj.name}")
    objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

    includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SABER_BUILD_DLL",
            "SABER_PLATFORM_WINDOWS"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
        }

    filter "configurations:Debug"
        defines "SB_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SB_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SB_DIST"
        optimize "On"


project "SandBox"
    location "SandBox"
    kind "ConsoleApp"
    language "C++"
    
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
        "%{wks.location}/Saber/src"
    }

    links
    {
        "Saber"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SABER_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "SB_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SB_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SB_DIST"
        optimize "On"