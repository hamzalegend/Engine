#include "Application.h"
#include "Window/Window.h"
#include "Log/log.h"

#include "Renderer/Renderer.h"
// #include "Camera/Camera.h"

#include <Jaguar/Scene/Scene.h>
#include <Jaguar/Scene/Components.h>
#include <Jaguar/Scene/Entity.h>

#include "Input/Input.h"

namespace Jaguar {
	class Camera;
	/*
	float verticesCube[] = {
		// positions          // normals           // texture coords
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
	};
	*/

	Scene* scene = new Scene;

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

	/*
	float lastX, lastY;
	bool firstMouse = true;
	void mouse_callback(GLFWwindow * window, double xpos, double ypos)
		{
			if (firstMouse)
			{
				lastX = xpos;
				lastY = ypos;
				firstMouse = false;
			}

			float xoffset = xpos - lastX;
			float yoffset = lastY - ypos;
			lastX = xpos;
			lastY = ypos;

			float sensitivity = 0.005f;
			xoffset *= sensitivity;
			yoffset *= sensitivity;

			cam->Rotation.x -= xoffset;
			cam->Rotation.y -= yoffset;

			if (cam->Rotation.x > 89.0f)
				cam->Rotation.x = 89.0f;
			if (cam->Rotation.x < -89.0f)
				cam->Rotation.x = -89.0f;
	}
	*/
	
	std::vector<float> Vertices = {
		// positions          // colors                // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 0.0f,   0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f, 0.0f,   0.0f, 1.0f    // top left 
	};
	
	std::vector<unsigned int> indices = {
		0, 1, 3,
		1, 2, 3,
	};	

	void Application::Run()
	{
		glfwSetFramebufferSizeCallback((GLFWwindow*)m_Window->GetNative(), framebuffer_size_callback);
		// glfwSetCursorPosCallback(window.m_window, mouse_callback);

		Entity e = scene->CreateEntity("Square");
		e.GetComponent<TransformComponent>().Transform = Mat4(1.0f);
		e.AddComponent<MeshRendererComponent>();
		e.GetComponent<MeshRendererComponent>().mesh.Vertices = Vertices;
		e.GetComponent<MeshRendererComponent>().mesh.indices = indices;
		e.GetComponent<MeshRendererComponent>().mesh.color = Vector4(25, 52, 63, 0);
		
		
		Entity camera = scene->CreateEntity("camera");
		camera.AddComponent<CameraComponent>();
		camera.GetComponent<CameraComponent>().cam = new Camera();
		Camera* cam = camera.GetComponent<CameraComponent>().cam;
		cam->Transform = &camera.GetComponent<TransformComponent>();

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
			// Move Player
			{
				TransformComponent& camTransform = camera.GetComponent<TransformComponent>();
				if (Input::GetKey(GLFW_KEY_D))
				{
					camTransform.Position.x -= deltaTime * 10;
				}
				else if (Input::GetKey(GLFW_KEY_A))
				{
					camTransform.Position.x += deltaTime * 10;
				}
				else if (Input::GetKey(GLFW_KEY_W))
				{
					camTransform.Position.z += deltaTime * 10;
				}
				else if (Input::GetKey(GLFW_KEY_S))
				{
					camTransform.Position.z -= deltaTime * 10;
				}
				else if (Input::GetKey(GLFW_KEY_E))
				{
					camTransform.Position.y -= deltaTime * 10;
				}
				else if (Input::GetKey(GLFW_KEY_Q))
				{
					camTransform.Position.y += deltaTime * 10;
				}
			}

			scene->OnUpdate(deltaTime);

			// old-new move
			{
				// float cameraSpeed = 5;
				// Vector3 WorldUp = Vector3(0, 1, 0);
				// Vector3 cameraUp = WorldUp;
				// cam->Update(deltaTime);
				// if (glfwGetKey(window.m_window, GLFW_KEY_W) == GLFW_PRESS)
				// 	cam->Position -= cameraSpeed * cam->Forward * deltaTime;
				// if (glfwGetKey(window.m_window, GLFW_KEY_S) == GLFW_PRESS)
				// 	cam->Position += cameraSpeed * cam->Forward * deltaTime;
				// if (glfwGetKey(window.m_window, GLFW_KEY_A) == GLFW_PRESS)
				// 	cam->Position -= glm::normalize(glm::cross(cam->Forward, cameraUp)) * cameraSpeed * deltaTime;
				// if (glfwGetKey(window.m_window, GLFW_KEY_D) == GLFW_PRESS)
				// 	cam->Position += glm::normalize(glm::cross(cam->Forward, cameraUp)) * cameraSpeed * deltaTime;
			} // move
			

			// Update Layers
			for (Layer* layer : m_LayerStack)
			{
				if (layer->IsEnabled())
					layer->OnUpdate();
			}
		}
	}
}

