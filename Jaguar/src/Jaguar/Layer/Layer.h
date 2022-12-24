#pragma once

#include"Jaguar/Core.h"

namespace Jaguar
{
	class JAGUAR_API Layer
	{
	public:
		Layer();
		virtual ~Layer();

		virtual void OnAttach();
		virtual void OnDetach();
		virtual void OnUpdate();
		virtual void OnEvent();

		inline void SetEnabled(bool enabled) { m_enabled = enabled; }
		inline bool IsEnabled() { return m_enabled; }

	private:
		bool m_enabled = true;
	};
}
