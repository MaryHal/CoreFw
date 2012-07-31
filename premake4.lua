solution "CoreFW"
    configurations { "Debug", "Release" }
    platforms { "native", "x32", "x64" }

    ---------------------------------------
    -- Static Library
    project "Core_Library"
        language "C++"

        includedirs { }

        files { "src/**" }

        targetdir "lib"
        targetname "CoreFW"

        --------------------------------------- 
        -- Link static libraries and config
        libdirs ("lib")
        links { "openal", "sndfile", "GLEW" }

        configuration "linux"
            links { "GL", "X11", "Xrandr", "pthread", "m", "glfw" }

        configuration "windows"
            links { "glfw", "opengl32" }

        configuration { "native or x64" }
            targetsuffix "64"

        configuration "x32"
            targetsuffix "32"

        --------------------------------------- 
        -- Build rules
        configuration "Debug"
            kind "StaticLib" 
            defines "DEBUG"
            flags { "Symbols", "ExtraWarnings" }
            --postbuildcommands { "sh make_includes" } 

        configuration "Release"
            kind "StaticLib"
            flags { "Optimize", "ExtraWarnings" }
            --postbuildcommands { "sh make_includes" } 


    project "test"
        language "C++"

        includedirs { "./src/" }

        files { "test/**" }


        targetdir "bin"
        targetname "Test"

        --------------------------------------- 
        -- Link static libraries and config
        libdirs ("lib")

        links { "Core_Library" }
        links { "openal", "sndfile", "GLEW" }

        configuration "linux"
            targetprefix "linux_"
            links { "GL", "X11", "Xrandr", "pthread", "m", "glfw" }

        configuration "windows"
            targetprefix "windows_"
            links { "glfw", "opengl32" }

        configuration { "native or x64" }
            links { "CoreFW64" }
            targetsuffix "64"

        configuration "x32"
            links { "CoreFW" }
            targetsuffix "32"

        --------------------------------------- 
        -- Build rules
        configuration "Debug"
            kind "ConsoleApp" 
            defines "DEBUG"
            flags { "Symbols", "ExtraWarnings" }

        configuration "Release"
            kind "ConsoleApp"
            flags { "Optimize", "ExtraWarnings" }

