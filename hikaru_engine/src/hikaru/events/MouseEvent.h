#pragma once

#include "Event.h"

#include <sstream>

namespace hikaru {

	class HIKARU_API mouse_moved_event : public event {
	public:
		mouse_moved_event(float x, float y) : m_mouseX(x), m_mouseY(y) {}
		inline float getX() const { return m_mouseX; }
		inline float getY() const { return m_mouseY; }

		std::string to_string() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent:" << m_mouseX << "," << m_mouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(mouse_moved)
		EVENT_CLASS_CATEGORY(event_category_mouse | event_category_input)

	private:
		float m_mouseX, m_mouseY;
	};

	class HIKARU_API mouse_scrolled_event : public event {
	public:
		mouse_scrolled_event(float X_offset, float Y_offset) : m_offsetX(X_offset), m_offsetY(Y_offset) {}

		inline float get_offsetX() const { return m_offsetX; }
		inline float get_offsetY() const { return m_offsetY; }

		std::string to_string() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent:" << get_offsetX() << "," << get_offsetY();
			return ss.str();
		}

		EVENT_CLASS_TYPE(mouse_scrolled)
		EVENT_CLASS_CATEGORY(event_category_mouse | event_category_input)

	private:
		float m_offsetX, m_offsetY;
	};

	class HIKARU_API mouse_button_event : public event {
		inline int get_mouse_button() const { return m_button; }

		EVENT_CLASS_CATEGORY(event_category_mouse | event_category_input)

	protected:
		mouse_button_event(int button) : m_button(button) {}
		int m_button;
	};

	class HIKARU_API mouse_button_released_event : public mouse_button_event {
	public:
		mouse_button_released_event(int button) : mouse_button_event(button) {}

		std::string to_string() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent:" << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(mouse_button_released)
	};

}