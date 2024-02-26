#pragma once

#ifdef GEWS_PLATFORM_WINDOWS
	#ifdef GEWS_BUILD_DLL
		#define GEWS_API __declspec(dllexport)
	#else
		#define GEWS_API __declspec(dllimport)
	#endif
#else
	#error Game Engine Workshop only supports Windows!
#endif
