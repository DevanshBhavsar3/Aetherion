#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Aetherion {

	class AETHERION_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger> GetClientLogger() { return s_ClientLogger; };
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core Log Macros
#define ATH_CORE_ERROR(...)  Aetherion::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ATH_CORE_WARN(...)   Aetherion::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ATH_CORE_INFO(...)   Aetherion::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ATH_CORE_TRACE(...)  Aetherion::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ATH_CORE_FATAL(...)  Aetherion::Log::GetCoreLogger()->fatal (__VA_ARGS__)

// Client Log Macros
#define ATH_ERROR(...)       Aetherion::Log::GetClientLogger()->error(__VA_ARGS__)
#define ATH_WARN(...)        Aetherion::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ATH_INFO(...)        Aetherion::Log::GetClientLogger()->info(__VA_ARGS__)
#define ATH_TRACE(...)       Aetherion::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ATH_FATAL(...)       Aetherion::Log::GetClientLogger()->fatal (__VA_ARGS__)