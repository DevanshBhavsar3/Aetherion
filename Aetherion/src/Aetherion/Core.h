#pragma once

#ifdef ATH_PLATFORM_WINDOWS
	#ifdef ATH_BUILD_DLL
		#define AETHERION_API _declspec(dllexport)
	#else
		#define AETHERION_API _declspec(dllimport)
	#endif
#else
	#error Aetherion only supports windows!
#endif

#ifdef ATH_ENABLE_ASSERTS
	#define ATH_ASSERT(x, ...) { if(!x) { ATH_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ATH_CORE_ASSERT(x, ...) { if(!x) { ATH_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ATH_ASSERT(x, ...)
	#define ATH_CORE_ASSERT(x, ...)
#endif

#define BIT(x) 1 << x