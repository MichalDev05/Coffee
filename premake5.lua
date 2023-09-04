workspace "Coffee"
    architecture "x64"
    configurations{
        "Debug",
        "Release",
        "Dist"
    }
    
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Coffee/vendor/GLFW/include"
IncludeDir["Glad"] = "Coffee/vendor/Glad/include"
IncludeDir["ImGui"] = "Coffee/vendor/imgui"

-- include premake5 from glfw here
include "Coffee/vendor/GLFW"
include "Coffee/vendor/Glad"
include "Coffee/vendor/imgui"

project "Coffee"
    location "Coffee"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "cfpch.h"
    pchsource "Coffee/src/cfpch.cpp"

    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links{
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "CF_PLATFORM_WINDOWS",
            "CF_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands{
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }


    filter "configurations:Debug"
        defines "CF_DEBUG"
        buildoptions "/MDd"
        symbols "On"
        
        filter "configurations:Release"
        defines "CF_RELEASE"
        buildoptions "/MD"
        optimize "On"
        
        filter "configurations:Dist"
        defines "CF_DIST"
        buildoptions "/MD"
        optimize "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
        "Coffee/vendor/spdlog/include",
        "Coffee/src"
    }


    links{
        "Coffee"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "CF_PLATFORM_WINDOWS"
        }


    filter "configurations:Debug"
        defines "CF_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "CF_RELEASE"
        buildoptions "/MD"
        optimize "On"
        
    filter "configurations:Dist"
        defines "CF_DIST"
        buildoptions "/MD"
        optimize "On"


