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
IncludeDirs["Glad"] = "Aetherion/vendor/Glad/include"

include "Aetherion/vendor/GLFW"
include "Aetherion/vendor/Glad"

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
		"%{IncludeDirs.GLFW}",
		"%{IncludeDirs.Glad}"
	}

	links {
		"GLFW",
		"Glad",
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
			"ATH_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands {
			("{MKDIR} ../bin/" .. outputdir .. "/Sandbox/"),
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/")
		}

	filter "configurations:Debug"
		defines {
			"ATH_DEBUG",
			"ATH_ENABLE_ASSERTS"
		}
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "ATH_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "ATH_DIST"
		buildoptions "/MD"
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
		defines {
			"ATH_DEBUG",
			"ATH_ENABLE_ASSERTS"
		}
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "ATH_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "ATH_DIST"
		buildoptions "/MD"
		optimize "On"