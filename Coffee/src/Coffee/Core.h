#pragma once

#ifdef CF_PLATFORM_WINDOWS
	#ifdef CF_BUILD_DLL
		#define COFFEE_API __declspec(dllexport)
	#else
		#define COFFEE_API __declspec(dllimport)
	#endif // CF_BUILD_DLL
#else
	#error Coffee supports only windows
#endif // CF_PLATFORM_WINDOWS

#define BIT(x) (1<<x)

