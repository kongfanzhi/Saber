#pragma once

#ifdef SABER_PLATFORM_WINDOWS
	#ifdef SABER_BUILD_DLL
		#define SABER_API _declspec(dllexport) 
	#else
		#define SABER_API _declspec(dllimport)
	#endif // DEBUG
#endif // SABER_ENGINE
