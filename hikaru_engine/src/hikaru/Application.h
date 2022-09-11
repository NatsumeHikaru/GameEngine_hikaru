#pragma once

#include "core.h"

namespace hikaru {

	class HIKARU_API application {
	public:
		application();
		~application();

		void run();
	};


	// to be define in CLIENT
	application* create_application();

}