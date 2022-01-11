workspace "CIT3DR"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CIT3DR"
    location "CIT3DR"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("int/" .. outputdir .. "/%{prj.name}")

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
            "CIT3DR_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "CIT3DR_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "CIT3DR_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "CIT3DR_Dist"
        optimize "On"
