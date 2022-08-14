-- Jaguar Solution setup
workspace "Jaguar"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Dist",
    }



output_directory = "%{cfg.builgcfg}-%{cfg.system}-%{cfg.architecture}"
-- Jaguar Project setup
project "Jaguar"
    location "Jaguar"
    kind "SharedLib"
    language "c++"

    targetdir ("bin/" .. output_directory .. "/%{prj.name}")
    objdir ("bin-int/" .. output_directory .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include;"
    }

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "on"
        systemversion "latest"

        defines
        {
            JR_PLATFORM_WINDOWS,
            JR_BUILD_DLL,
        }
    
    
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. output_directory .. "/SandBox")
        }

    filter "configurations:Debug"
        defines "JR_DEBUG"
        symbols "on"        

    filter "configurations:Release"
        defines "JR_RELEASE"
        optimize "on"

    filter "configurations:Dist"
        defines "JR_DIST"
        optimize "on"

    
    


-- sandBox Project setup


project "SandBox"
    location "SandBox"
    kind "consoleApp"
    language "c++"

    targetdir ("bin/" .. output_directory .. "/%{prj.name}")
    objdir ("bin-int/" .. output_directory .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Jaguar/vendor/spdlog/include;",
        "Jaguar/src",
    }

    links 
    {
        "Jaguar",
    }

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "on"
        systemversion "latest"

        defines
        {
            JR_PLATFORM_WINDOWS,
            
        }

    filter "configurations:Debug"
        defines "JR_DEBUG"
        symbols "on"        

    filter "configurations:Release"
        defines "JR_RELEASE"
        optimize "on"

    filter "configurations:Dist"
        defines "JR_DIST"
        optimize "on"

    