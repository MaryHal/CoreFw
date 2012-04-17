solution "CoreFW"
    configurations { "Debug", "Release" }
    platforms { "native", "x32", "x64" }

    project "test"
        language "C++"

        includedirs { "./include/" }

        files { "test/**" }

        targetdir "bin"
        targetname "Test"

        --------------------------------------- 
        -- Link static libraries and config
        libdirs ("lib")
        links { "GLEW" }

        configuration "linux"
            targetprefix "linux_"
            links { "GL", "X11", "Xrandr", "pthread", "m", "glfw" }

        configuration "windows"
            targetprefix "windows_"
            links { "glfw", "opengl32" }

        configuration { "native or x64" }
            links { "fmodex64", "CoreFW64" }
            targetsuffix "64"

        configuration "x32"
            links { "fmodex", "CoreFW" }
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

    ---------------------------------------
    -- Static Library
    project "library"
        language "C++"

        includedirs { "/usr/include/freetype2/" }

        files { "src/**" }

        targetdir "lib"
        targetname "CoreFW"

        --------------------------------------- 
        -- Link static libraries and config
        libdirs ("lib")
        links { "GLEW", "freetype" }

        configuration "linux"
            links { "GL", "X11", "Xrandr", "pthread", "m", "glfw" }

        configuration "windows"
            links { "glfw", "opengl32" }

        configuration { "native or x64" }
            links { "fmodex64" }
            targetsuffix "64"

        configuration "x32"
            links { "fmodex" }
            targetsuffix "32"

        --------------------------------------- 
        -- Build rules
        configuration "Debug"
            kind "StaticLib" 
            defines "DEBUG"
            flags { "Symbols", "ExtraWarnings" }
            postbuildcommands { "sh make_includes" } 

        configuration "Release"
            kind "StaticLib"
            flags { "Optimize", "ExtraWarnings" }
            postbuildcommands { "sh make_includes" } 

