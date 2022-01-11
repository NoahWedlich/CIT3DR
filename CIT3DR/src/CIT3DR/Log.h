#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace CITR
{

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return _Logger; }
	private:
		static std::shared_ptr<spdlog::logger> _Logger;
	};

}

#define LOG_DEBUG(...) ::CITR::Log::GetLogger()->debug(__VA_ARGS__)
#define LOG_TRACE(...) ::CITR::Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...) ::CITR::Log::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...) ::CITR::Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::CITR::Log::GetLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...) ::CITR::Log::GetLogger()->critical(__VA_ARGS__)

