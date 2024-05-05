#pragma once

#include <memory.h>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Saber
{
	class SABER_API Log
	{
	public:
		Log();
		~Log();
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#define SB_CORE_ERROR(...) ::Saber::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SB_CORE_WARN(...) ::Saber::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SB_CORE_INFO(...) ::Saber::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SB_CORE_TRACE(...) ::Saber::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SB_CORE_FATAL(...) ::Saber::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define SB_ERROR(...)   ::Saber::Log::GetClientLogger()->error(__VA_ARGS__)
#define SB_WARN(...)    ::Saber::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SB_INFO(...)    ::Saber::Log::GetClientLogger()->info(__VA_ARGS__)
#define SB_TRACE(...)   ::Saber::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SB_FATAL(...)   ::Saber::Log::GetClientLogger()->fatal(__VA_ARGS__)