#pragma once

#include "Core.h"
#include "events/Event.h"

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