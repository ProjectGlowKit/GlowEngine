#pragma once

#ifdef GWE_PLATFORM_WINDOWS
	#ifdef GWE_BUILD_DLL
		#define GLOW_API __declspec(dllexport)
	#else
		#define GLOW_API __declspec(dllimport)
	#endif //GWE_BUILD_DLL
#else
	#error Glow Engine only supports Windows
#endif //GWE_PLATFORM_WINDOWS

#define BIT(x) (1 << x)