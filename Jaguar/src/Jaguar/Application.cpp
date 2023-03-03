#include "Application.h"
#include "Window/Window.h"
#include "Log/log.h"

#include "Renderer/Renderer.h"
#include "Camera/Camera.h"

#include "API/Texture.h"
#include "API/Shader.h"
#include "API/Buffer.h"

namespace Jaguar {

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

	Window window;
	Camera* cam = new Camera(&window);


	Application::Application()
	{
		
		window.Create(Vector2(600, 600), "Hello OpenGL");

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
		window.Resize(Vector2(width, height));
	}
	
	float Vertices[] = {
		// positions          // colors                // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 0.0f,   0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f, 0.0f,   0.0f, 1.0f    // top left 
	};
	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3,
	};	

	void Application::Run()
	{
		glfwSetFramebufferSizeCallback(window.m_window, framebuffer_size_callback);
		// glfwSetCursorPosCallback(window.m_window, mouse_callback);

	
		VertexBuffer* vb = VertexBuffer::Create(Vertices, sizeof(Vertices));
		vb->Bind();
		IndexBuffer* ib = IndexBuffer::Create(indices, sizeof(indices) / sizeof(float));
		ib->Bind();
		VertexArray* va = VertexArray::Create();
		va->SetIndexBuffer(ib);
		va->Bind();
		va->AddLayout(3);
		va->AddLayout(4);
		va->AddLayout(2);
		va->Push();
		
		Shader* shader = Shader::Create("src/shaders/Texture.vshader", "src/shaders/Texture.fshader");
		shader->Bind();
		Texture* texture = Texture::Create("src/Images/awesomeface.png", 0, true);
		texture->Bind();
		shader->SetUniform1i("Texture0", 0);

		Mat4 Transform = Mat4(1.0f);

		cam->Position.z = -4;

		float deltaTime, lastFrame = 0;
		while (!glfwWindowShouldClose(window.m_window))
		{
			window.Refresh();

			// Move Player
			{ 
				float currentFrame = glfwGetTime();
				deltaTime = currentFrame - lastFrame;
				lastFrame = currentFrame;

				if (glfwGetKey(window.m_window, GLFW_KEY_D))
				{
					cam->Position.x -= deltaTime * 10;
				}
				else if (glfwGetKey(window.m_window, GLFW_KEY_A))
				{
					cam->Position.x += deltaTime * 10;
				}
				else if (glfwGetKey(window.m_window, GLFW_KEY_W))
				{
					cam->Position.z += deltaTime * 10;
				}
				else if (glfwGetKey(window.m_window, GLFW_KEY_S))
				{
					cam->Position.z -= deltaTime * 10;
				}
				else if (glfwGetKey(window.m_window, GLFW_KEY_E))
				{
					cam->Position.y -= deltaTime * 10;
				}
				else if (glfwGetKey(window.m_window, GLFW_KEY_Q))
				{
					cam->Position.y += deltaTime * 10;
				}
			} // move
			
			// Render
			{  
				Renderer::BeginScene(cam);
				Renderer::Submit(va, shader, Transform);
				Renderer::Flush();
				Renderer::EndScene();		
			}

			// Update Layers
			for (Layer* layer : m_LayerStack)
			{
				if (layer->IsEnabled())
					layer->OnUpdate();
			}
		}
	}
}

