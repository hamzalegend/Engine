#pragma once

#include "Jaguar/Core.h"
#include <String>

namespace Jaguar
{
	class JAGUAR_API Event
	{
	public:
		virtual static enum class Catigoty
		{
			None = 0,
			custom,
			window,
			Input,
		};

		Event(std::string name = "EventName") :m_name(name) {}
		~Event() {}

		std::string GetName() const { return m_name; }

		bool m_Handeled = false;
		bool m_BlockWhenHandeled = true;
	private:
		
		std::string m_name = "";
		
		// friend Application;
	};
}