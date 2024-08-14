
workspace "CWLHackathon"
    filename "CWLHackathon"
    language "C++"
    location "CWLHackathon"
    configurations { "Debug", "Release" }
    platforms { "x64" }

project "CWLHackathon"
    location "CWLHackathon/CWLHackathon"
    kind "ConsoleApp"
    files
    {
        "%{wks.name}/%{prj.name}/src/**.cpp",
        "%{wks.name}/%{prj.name}/include/**.hpp",
        "%{wks.name}/%{prj.name}/src/**.c",
        "%{wks.name}/%{prj.name}/include/**.h",
    }
    includedirs
    {
        "%{wks.name}/%{prj.name}/include"
    }
    targetdir "SuperPong/bin/SuperPong/%{cfg.buildcfg}"
    objdir "SuperPong/bin/intermediates/SuperPong/%{cfg.buildcfg}"

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"
        optimize "Off"

    filter "configurations:Release"
        defines "RELEASE"
        symbols "Off"
        optimize "On"