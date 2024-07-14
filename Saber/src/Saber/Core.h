#pragma once

#ifdef SABER_PLATFORM_WINDOWS
#if SB_DYNAMIC_LINK
	#ifdef SABER_BUILD_DLL
		#define SABER_API _declspec(dllexport) 
	#else
		#define SABER_API _declspec(dllimport)
	#endif // DEBUG
#else
	#define SABER_API
#endif

#else
	#error saber only support windows

#endif // SABER_ENGINE

#ifdef SB_ENABLE_ASSERTS
	#define SB_ASSERT(x, ...) { if(!(x)) { SB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SB_CORE_ASSERT(x, ...) { if(!(x)) { SB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SB_ASSERT(x, ...)
	#define SB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define SB_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
