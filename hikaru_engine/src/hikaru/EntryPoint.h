#pragma once

#ifdef HIKARU_PLATFORM_WINDOWS

extern hikaru::Application* hikaru::create_application();

int main(int argc, char** argv) {
	auto app = hikaru::create_application();
	app->run();
	delete app;

	return 0;
}

#endif
