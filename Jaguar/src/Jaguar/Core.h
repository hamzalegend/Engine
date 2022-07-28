#pragma once
#ifdef JR_PLATFORM_WINDOWS
	#ifdef JR_BUILD_DLL
		#define JAGUAR_API __declspec(dllexport)
	#else
		#define JAGUAR_API __declspec(dllimport)
	#endif
#else
	#error JAGUAR only supports windows!
#endif
