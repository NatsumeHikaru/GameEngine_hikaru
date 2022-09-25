#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace hikaru {

	class HIKARU_API log {
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& get_core_logger() { return s_core_logger; }
		inline static std::shared_ptr<spdlog::logger>& get_client_logger() { return s_client_logger; }
	private:
		static std::shared_ptr<spdlog::logger> s_core_logger;
		static std::shared_ptr<spdlog::logger> s_client_logger;
	};
}

// core log macros
#define HIKARU_CORE_ERROR(...) ::hikaru::log::get_core_logger()->error(__VA_ARGS__)
#define HIKARU_CORE_INFO(...) ::hikaru::log::get_core_logger()->info(__VA_ARGS__)
#define HIKARU_CORE_WARN(...) ::hikaru::log::get_core_logger()->warn(__VA_ARGS__)
#define HIKARU_CORE_TRACE(...) ::hikaru::log::get_core_logger()->trace(__VA_ARGS__)
#define HIKARU_CORE_FATAL(...) ::hikaru::log::get_core_logger()->fatal(__VA_ARGS__)

#define HIKARU_ERROR(...) ::hikaru::log::get_client_logger()->error(__VA_ARGS__)
#define HIKARU_INFO(...) ::hikaru::log::get_client_logger()->info(__VA_ARGS__)
#define HIKARU_WARN(...) ::hikaru::log::get_client_logger()->warn(__VA_ARGS__)
#define HIKARU_TRACE(...) ::hikaru::log::get_client_logger()->trace(__VA_ARGS__)
#define HIKARU_FATAL(...) ::hikaru::log::get_client_logger()->fatal(__VA_ARGS__)
