#pragma once

#include"Jaguar/Core.h"
#include "Jaguar/Event/Event.h"
#include "Jaguar/Log/log.h"

namespace Jaguar
{
	class JAGUAR_API Layer
	{
	public:
		Layer();
		virtual ~Layer();

		virtual void OnAttach();
		virtual void OnDetach();
		virtual void OnUpdate(float DeltaTime);
		virtual void OnEvent(Event& event);

		inline void SetEnabled(bool enabled) { m_enabled = enabled; }
		inline bool IsEnabled() { return m_enabled; }

	private:
		bool m_enabled = true;
	};
}
