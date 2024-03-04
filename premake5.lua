workspace "GE_workshop"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GE_workshop"
	location "GE_workshop"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GEWS_PLATFORM_WINDOWS",
			"GEWS_BUILD_DLL",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "GEWS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GEWS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GEWS_DIST"
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
		"GE_workshop/vendor/spdlog/include",
		"GE_workshop/src"
	}

	links
	{
		"GE_workshop"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GEWS_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "GEWS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GEWS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GEWS_DIST"
		optimize "On"
