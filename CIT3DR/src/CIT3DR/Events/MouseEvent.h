#pragma once

#include "Event.h"

#include <sstream>

namespace CITR
{

	class MousePressedEvent : public Event
	{
	public:
		MousePressedEvent(int button)
			: _button(button) {}

		inline int getButton() const { return _button; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MousePressedEvent: " << _button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MousePressed)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	private:
		int _button;
	};

	class MouseReleasedEvent : public Event
	{
	public:
		MouseReleasedEvent(int button)
			: _button(button) {}

		inline int getButton() const { return _button; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseReleasedEvent: " << _button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseReleased)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	private:
		int _button;
	};

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float newX, float newY)
			: _newX(newX), _newY(newY) {}

		inline float getNewX() const { return _newX; }
		inline float getNewY() const { return _newY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << "Moved to (" << _newX << " | " << _newY << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	private:
		float _newX, _newY;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float offX, float offY)
			: _offX(offX), _offY(offY) {}

		inline float getOffX() const { return _offX; }
		inline float getOffY() const { return _offY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << "(" << _offX << " | " << _offY << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	private:
		float _offX, _offY;
	};

}