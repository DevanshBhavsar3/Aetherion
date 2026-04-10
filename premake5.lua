workspace "Aetherion"
	architecture "x64"

	startproject "Sandbox"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDirs = {}
IncludeDirs["spdlog"] = "Aetherion/vendor/spdlog/include"
IncludeDirs["GLFW"] = "Aetherion/vendor/GLFW/include"

include "Aetherion/vendor/GLFW"

project "Aetherion"
	location "Aetherion"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermediates/" .. outputdir .. "/%{prj.name}")

	pchheader "athpch.h"
	pchsource "Aetherion/src/athpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{IncludeDirs.spdlog}",
		"%{IncludeDirs.GLFW}"
	}

	links {
		"GLFW",
		"opengl32.lib",
		"dwmapi.lib"
	}

	buildoptions {
		"/utf-8"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"ATH_PLATFORM_WINDOWS",
			"ATH_BUILD_DLL"
		}

		postbuildcommands {
			("{MKDIR} ../bin/" .. outputdir .. "/Sandbox/"),
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/")
		}

	filter "configurations:Debug"
		defines "ATH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ATH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ATH_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermediates/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Aetherion/src",
		"%{IncludeDirs.spdlog}"
	}
	
	links {
		"Aetherion"
	}

	buildoptions {
		"/utf-8"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"ATH_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ATH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ATH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ATH_DIST"
		optimize "On"