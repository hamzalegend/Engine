#pragma once

#include "Core.h"
#include "Layer/Layer.h"
#include "Layer/LayerStack.h"
namespace Jaguar {
	class JAGUAR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		void Run();

	private:
		LayerStack m_LayerStack;
	};
	// to be defined in client
	Application* CreateApplication();
}