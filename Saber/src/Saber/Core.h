#pragma once

#ifdef SABER_PLATFORM_WINDOWS
	#ifdef SABER_BUILD_DLL
		#define SABER_API _declspec(dllexport) 
	#else
		#define SABER_API _declspec(dllimport)
	#endif // DEBUG

#else
	#error saber only support windows

#endif // SABER_ENGINE

#define BTT(x) (1 << x)
