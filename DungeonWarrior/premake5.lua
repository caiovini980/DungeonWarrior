project "DungeonWarrior"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("../bin/" .. outputdir .. "/%{prj.name}")
    objdir("../bin-int/" .. outputdir .. "/%{prj.name}")
    
    files {
        "Assets/**.png",
        "Libraries/**.hpp",
        "Source/**.cpp",
        "Source/**.h",
        "Settings/**.json",
    }

    includedirs { "../Include/required-includes" } -- C/C++ -> General -> Additional Include Directories
    
    libdirs { "../Include/required-libs" } -- Linker -> General -> Additional Library Directories

    links { -- Linker -> Input -> Additional Dependencies
        "SDL2", 
        "SDL2main", 
        "SDL2_image" 
    } 

    defines {
        "WINDOWS"
    }

    postbuildcommands {
        ("{COPY} ../Include/required-dlls/ ../bin/" .. outputdir .. "/%{prj.name}"),
    }

    filter { "configurations:Debug" }
        buildoptions "/MTd"
        staticruntime "off" -- C/C++ -> Code Generation -> Runtime Library (/MD)
        runtime "Debug"
        symbols "on"

    filter { "configurations:Release" }
        buildoptions "/MT"
        runtime "Release"
        optimize "on"