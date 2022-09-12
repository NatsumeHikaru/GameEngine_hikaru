#pragma once

#ifdef HIKARU_PLATFORM_WINDOWS

extern hikaru::application* hikaru::create_application();

int main(int argc, char** argv) {
	hikaru::log::init();
	HIKARU_CORE_WARN("Initialized Log!");
	int a = 5;
	HIKARU_INFO("value = {0}", a);

	auto app = hikaru::create_application();
	app->run();
	delete app;

	return 0;
}

#endif
