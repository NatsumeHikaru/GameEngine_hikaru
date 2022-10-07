#include "hikaru_pch.h"
#include "Application.h"

#include "events/ApplicationEvent.h"
#include "Log.h"

namespace hikaru {

	application::application() {

	}

	application::~application() {

	}

	void application::run() {
		window_resize_event e(1200, 720);
		HIKARU_TRACE(e);

		while (true);
	}
}