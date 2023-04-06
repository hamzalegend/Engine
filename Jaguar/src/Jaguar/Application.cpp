#include "Application.h"
#include "Window/Window.h"
#include "Log/log.h"

#include "Renderer/Renderer.h"
#include "Camera/Camera.h"

#include "Jaguar/Scene/Scene.h"
#include "Jaguar/Scene/Components.h"
#include "Jaguar/Scene/Entity.h"

#include "Input/Input.h"

// ==

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

// ==

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
		

		// ====================================================================================
		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
		ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
		ImGui::StyleColorsDark();
		ImGui::GetStyle().WindowRounding = 0.0f;
		ImGui::GetStyle().Colors[ImGuiCol_WindowBg].w = 1.0f;

		ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)m_Window->GetNative(), true);
		ImGui_ImplOpenGL3_Init("#version 330");

		// ====================================================================================



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

			{
				// Start the Dear ImGui frame
				ImGui_ImplOpenGL3_NewFrame();
				ImGui_ImplGlfw_NewFrame();
				ImGui::NewFrame();
				// 
				ImGui::ShowDemoWindow(nullptr);
				//
				ImGui::Render();
				ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
				//
				GLFWwindow* backup_current_context = glfwGetCurrentContext();
				ImGui::UpdatePlatformWindows();
				ImGui::RenderPlatformWindowsDefault();
				glfwMakeContextCurrent(backup_current_context);

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

