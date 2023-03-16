#include "Application.h"
#include "Window/Window.h"
#include "Log/log.h"

#include "Renderer/Renderer.h"
#include "Camera/Camera.h"

#include "Jaguar/Scene/Scene.h"
#include "Jaguar/Scene/Components.h"
#include "Jaguar/Scene/Entity.h"

#include "Input/Input.h"

namespace Jaguar {

	Application* Application::s_Instance = nullptr;
	Application::Application()
	{
		JR_CORE_ASSERT(s_Instance, "Application already exists")
		s_Instance = this;
		m_Window = new Window;
		m_Window->Create(Vector2(600, 600), "Hello OpenGL");

		Renderer::Init(Renderer::API::OpenGL);
	}
	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}	 
	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}
	void Application::OnEvent(Event& event)
	{
		for (Layer* layer : m_LayerStack)
		{
			if (layer->IsEnabled())
			{
				if(!event.m_Handeled)
					layer->OnEvent(event);
				else
				{
					if (!event.m_BlockWhenHandeled)
						layer->OnEvent(event);
				}
			}
		}
	}

	void framebuffer_size_callback(GLFWwindow* Window, int width, int height)
	{
		Application::Get().GetWindow()->Resize(Vector2(width, height));
	}

	void Application::Run()
	{
		glfwSetFramebufferSizeCallback((GLFWwindow*)m_Window->GetNative(), framebuffer_size_callback);
		// glfwSetCursorPosCallback(window.m_window, mouse_callback);

		// Attach Layers
		for (Layer* layer : m_LayerStack)
		{
			if (layer->IsEnabled())
				layer->OnAttach();
		}

		float deltaTime, lastFrame = 0;
		while (!glfwWindowShouldClose((GLFWwindow*)m_Window->GetNative()))
		{
			m_Window->Refresh();

			// DeltaTime
			{
				float currentFrame = glfwGetTime();
				deltaTime = currentFrame - lastFrame;
				lastFrame = currentFrame;
			}


			// Update Layers
			for (Layer* layer : m_LayerStack)
			{
				if (layer->IsEnabled())
					layer->OnUpdate(deltaTime);
			}
		}
	}
}

