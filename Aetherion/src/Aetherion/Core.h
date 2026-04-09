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

#define BIT(x) 1 << x