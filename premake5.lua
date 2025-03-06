workspace "GlowEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GlowEngine"
    location "GlowEngine"
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
        "%{prj.name}/src",
        "%{prj.name}/thirdparty/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

    filter "action:vs*"
        buildoptions { "/utf-8" }

        defines
        {
            "GWE_PLATFORM_WINDOWS", 
            "GWE_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "GWE_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "GWE_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "GWE_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
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
        "GlowEngine/thirdparty/spdlog/include",
        "GlowEngine/src"
    }

    links
    {
        "GlowEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
    
    filter "action:vs*"
        buildoptions { "/utf-8" }

        defines
        {
            "GWE_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "GWE_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "GWE_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "GWE_DIST"
        optimize "On"