#pragma once

#include "Event.h"

#include <sstream>

namespace Saber
{
	class SABER_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			:m_width(width), m_height(height) {}

		inline unsigned int GetWidth() const { return m_width; }
		inline unsigned int GetHeight() const { return m_height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_width << "," << m_height;
			return ss.str();
		}

	private:
		unsigned int m_width, m_height;
	};
}