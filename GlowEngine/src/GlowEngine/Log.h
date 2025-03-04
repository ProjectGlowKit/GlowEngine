#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Glow
{
	class GLOW_API Log
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

//Core Log Defines
#define GWE_CORE_FATAL(...) ::Glow::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define GWE_CORE_ERROR(...) ::Glow::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GWE_CORE_WARN(...)  ::Glow::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GWE_CORE_INFO(...)  ::Glow::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GWE_CORE_TRACE(...) ::Glow::Log::GetCoreLogger()->trace(__VA_ARGS__)

//Client Log Defines
#define GWE_FATAL(...) ::Glow::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define GWE_ERROR(...) ::Glow::Log::GetClientLogger()->error(__VA_ARGS__)
#define GWE_WARN(...)  ::Glow::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GWE_INFO(...)  ::Glow::Log::GetClientLogger()->info(__VA_ARGS__)
#define GWE_TRACE(...) ::Glow::Log::GetClientLogger()->trace(__VA_ARGS__)