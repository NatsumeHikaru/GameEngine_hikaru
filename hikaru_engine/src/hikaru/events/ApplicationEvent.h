#pragma once

#include "Event.h"

#include <sstream>

namespace hikaru {
	class HIKARU_API window_resize_event : public event {
	private:
		unsigned int m_width, m_height;
	public:
		window_resize_event(unsigned int width, unsigned int height) : m_width(width), m_height(height) {}

		inline unsigned int get_width() const { return m_width; }
		inline unsigned int get_height() const { return m_height; }

		std::string to_string() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent:" << m_width << "," << m_height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(window_resize)
		EVENT_CLASS_CATEGORY(event_category_application)
	};

	class HIKARU_API app_tick_event : public event {
		app_tick_event() {}

		EVENT_CLASS_TYPE(app_tick);
		EVENT_CLASS_CATEGORY(event_category_application);
	};

	class HIKARU_API app_update_event : public event {
		app_update_event() {}

		EVENT_CLASS_TYPE(app_render);
		EVENT_CLASS_CATEGORY(event_category_application);
	};
}