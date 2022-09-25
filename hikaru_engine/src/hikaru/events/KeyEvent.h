#pragma once

#include "Event.h"

#include <sstream>

namespace hikaru {
	class HIKARU_API key_event : public event {
	public :
		inline int ger_keycode() const { return m_keycode; }

		EVENT_CLASS_CATEGORY(event_category_keyboard | event_category_input)
	protected:
		key_event(int keycode) : m_keycode(keycode) {}
		int m_keycode;
	};

	class HIKARU_API key_pressed_event : public key_event {
		key_pressed_event(int keycode,int repeat_count) : key_event(keycode), m_repeat_count(repeat_count) {}

		inline int get_repeat_count() const { return m_repeat_count; }

		std::string to_string() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent:" << m_keycode << "(" << m_repeat_count << "repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(key_pressed);
	private:
		int m_repeat_count;
	};

	class HIKARU_API key_released_event : public key_event {
	public:
		key_released_event(int keycode) : key_event(keycode) {}

		std::string to_string() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent:" << m_keycode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(key_released);
	};
}