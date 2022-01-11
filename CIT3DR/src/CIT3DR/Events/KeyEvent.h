#pragma once

#include "Event.h"

#include <sstream>

namespace CITR
{

	class KeyPressed : public Event
	{
	public:
		KeyPressed(int keyCode, int repeatCount)
			: _keyCode(keyCode), _repeatCount(repeatCount) {}

		inline int getKeyCode() const { return _keyCode; }
		inline int getRepeatCount() const { return _repeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << _keyCode << "-" << _repeatCount << "x";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	private:
		int _keyCode, _repeatCount;
	};

	class KeyReleasedEvent : public Event
	{
	public:
		KeyReleasedEvent(int keyCode)
			: _keyCode(keyCode) {}

		inline int getKeyCode() const { return _keyCode; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleased: " << _keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	private:
		int _keyCode;
	};
}
