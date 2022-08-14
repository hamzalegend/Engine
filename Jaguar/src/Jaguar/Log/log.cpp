#include "log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

namespace Jaguar {

	std::shared_ptr<spdlog::logger> Log::S_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::S_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		
		S_CoreLogger = spdlog::stdout_color_mt("JAGUAR");
		S_CoreLogger->set_level(spdlog::level::trace);

		S_ClientLogger = spdlog::stdout_color_mt("APP");
		S_ClientLogger->set_level(spdlog::level::trace);
	}
}

