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

#ifdef CF_ENABLE_ASSERTS
	#define CF_ASSERT(x, ...) {if(!(x)) {LOG_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define CF_CORE_ASSERT(x, ...) {if(!(x)) {LOG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define CF_ASSERT(x, ...)
	#define CF_CORE_ASSERT(x, ...)
#endif // CF_ENABLE_ASSERTS



#define BIT(x) (1<<x)

