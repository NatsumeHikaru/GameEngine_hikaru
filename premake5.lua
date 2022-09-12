workspace "hikaru_engine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "hikaru_engine"
    location "hikaru_engine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

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
        systemversion "10.0.19041.0"

        defines{
            "HIKARU_PLATFORM_WINDOWS",
            "HIKARU_BUILD_DLL",
            "_WINDLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/box")
        }

    filter "configurations:Debug"
        defines "HIKARU_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "HIKARU_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "HIKARU_DIST"
        optimize "On"

project "box"
    location "box"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "hikaru_engine/vendor/spdlog/include",
        "hikaru_engine/src"
    }

    links{
        "hikaru_engine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.19041.0"

        defines{
            "HIKARU_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "HIKARU_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "HIKARU_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "HIKARU_DIST"
        optimize "On"