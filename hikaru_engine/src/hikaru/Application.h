#pragma once

#include "core.h"

namespace hikaru {

	class HIKARU_API Application {
	public:
		Application();
		~Application();

		void run();
	};


	// to be define in CLIENT
	Application* create_application();

}