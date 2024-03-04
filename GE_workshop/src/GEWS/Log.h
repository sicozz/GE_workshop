#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace GEWS
{
	class GEWS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define GEWS_CORE_TRACE(...)    ::GEWS::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GEWS_CORE_INFO(...)     ::GEWS::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GEWS_CORE_WARN(...)	    ::GEWS::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GEWS_CORE_ERROR(...)    ::GEWS::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GEWS_CORE_FATAL(...)    ::GEWS::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define GEWS_TRACE(...)         ::GEWS::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GEWS_INFO(...)          ::GEWS::Log::GetClientLogger()->info(__VA_ARGS__)
#define GEWS_WARN(...)	        ::GEWS::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GEWS_ERROR(...)         ::GEWS::Log::GetClientLogger()->error(__VA_ARGS__)
#define GEWS_FATAL(...)         ::GEWS::Log::GetClientLogger()->fatal(__VA_ARGS__)
