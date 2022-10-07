#include "hikaru_pch.h"

#include "Log.h"

namespace hikaru {
	std::shared_ptr<spdlog::logger> log::s_core_logger;
	std::shared_ptr<spdlog::logger> log::s_client_logger;

	void log::init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_core_logger = spdlog::stdout_color_mt("hikaru");
		s_core_logger->set_level(spdlog::level::trace);

		s_client_logger = spdlog::stdout_color_mt("app");
		s_client_logger->set_level(spdlog::level::trace);
	}
}