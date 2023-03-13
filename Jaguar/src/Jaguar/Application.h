#pragma once

#include "Core.h"
// #include "GLFW/glfw3.h"
#include "Layer/Layer.h"
#include "Layer/LayerStack.h"
#include "Window/Window.h"

namespace Jaguar {
	class JAGUAR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		static Application& Get() { return *s_Instance; }

		void OnEvent(Event& event);

		void Run();

		Window* GetWindow() { return m_Window; };

	private:
		static Application* s_Instance;
		Window* m_Window;
		LayerStack m_LayerStack;
	};
	// to be defined in client
	Application* CreateApplication();

	
}