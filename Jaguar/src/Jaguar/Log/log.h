#pragma once

#include <memory>
#include "../Core.h"
#include <spdlog/spdlog.h>


namespace Jaguar {

	class JAGUAR_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return S_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return S_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> S_CoreLogger;
		static std::shared_ptr<spdlog::logger> S_ClientLogger;
	};
}

#ifdef JR_DIST

	#define JR_CORE_TRACE(...);
	#define JR_CORE_INFO(...);
	#define JR_CORE_WARN(...);
	#define JR_CORE_ERROR(...);
	#define JR_CORE_FATAL(...);
	
	
	
	#define JR_TRACE(...);
	#define JR_INFO(...) ;
	#define JR_WARN(...) ;
	#define JR_ERROR(...);
	#define JR_FATAL(...);

#else
	//Engine Core Logging
	#define JR_CORE_TRACE(...)	::Jaguar::Log::GetCoreLogger()->trace(__VA_ARGS__);
	#define JR_CORE_INFO(...) 	::Jaguar::Log::GetCoreLogger()->info(__VA_ARGS__);
	#define JR_CORE_WARN(...) 	::Jaguar::Log::GetCoreLogger()->warn(__VA_ARGS__);
	#define JR_CORE_ERROR(...) 	::Jaguar::Log::GetCoreLogger()->error(__VA_ARGS__);
	#define JR_CORE_CRITICAL(...)	::Jaguar::Log::GetCoreLogger()->critical(__VA_ARGS__);
	
	//Client Logging
	
	#define JR_TRACE(...)	::Jaguar::Log::GetClientLogger()->trace(__VA_ARGS__);
	#define JR_INFO(...) 	::Jaguar::Log::GetClientLogger()->info(__VA_ARGS__);
	#define JR_WARN(...) 	::Jaguar::Log::GetClientLogger()->warn(__VA_ARGS__);
	#define JR_ERROR(...) 	::Jaguar::Log::GetClientLogger()->error(__VA_ARGS__);
	#define JR_CRITICAL(...)	::Jaguar::Log::GetClientLogger()->critical(__VA_ARGS__);

#endif