#include "Log.h"

namespace CITR
{
	std::shared_ptr<spdlog::logger> Log::_Logger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%R] %n: %v%$");
		_Logger = spdlog::stdout_color_mt("CIT3DR");
		_Logger->set_level(spdlog::level::trace);
		LOG_INFO("Logger initialized!");
	}
}
