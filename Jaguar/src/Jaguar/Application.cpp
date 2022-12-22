#include "GL/glew.h"

#include "Application.h"
#include "Window/Window.h"
#include "Log/log.h"

#include "Renderer/Renderer.h"
#include "Camera/Camera.h"

#include "API/Texture.h"
#include "API/Shader.h"
#include "API/Buffer.h"

#include <iostream>


namespace Jaguar {


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

	Window window;

	Application::Application()
	{
		
		window.Create(600, 600, "Hello OpenGL");

		if (glewInit() != GLEW_OK)
		{
			JR_CORE_ERROR("Could Not Initialize The OpenGL Context")
			return;
		}
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glViewport(0, 0, window.width, window.height);
		
	}

	Application::~Application()
	{
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

		if (RendererAPI::Get_API() == RendererAPI::API::OpenGL)
			JR_CORE_INFO("Using OpenGL as the Defult API");

		VertexBuffer* vb = VertexBuffer::Create(Vertices, sizeof(Vertices));
		vb->Bind();
		IndexBuffer* ib = IndexBuffer::Create(indices, sizeof(indices) / sizeof(float));
		ib->Bind();
		VertexArray* va = VertexArray::Create();
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

		Mat4 model = Mat4(1.0f);

		Camera cam(Vector2(window.width, window.height));
		cam.Position.z = -4;

		float deltaTime, lastFrame = 0;
		while (!glfwWindowShouldClose(window.m_window))
		{
			window.Refresh();
			{ // Move
				float currentFrame = glfwGetTime();
				deltaTime = currentFrame - lastFrame;
				lastFrame = currentFrame;

				if (glfwGetKey(window.m_window, GLFW_KEY_D))
				{
					cam.Position.x -= deltaTime * 10;
				}
				else if (glfwGetKey(window.m_window, GLFW_KEY_A))
				{
					cam.Position.x += deltaTime * 10;
				}
				else if (glfwGetKey(window.m_window, GLFW_KEY_W))
				{
					cam.Position.z += deltaTime * 10;
				}
				else if (glfwGetKey(window.m_window, GLFW_KEY_S))
				{
					cam.Position.z -= deltaTime * 10;
				}
				else if (glfwGetKey(window.m_window, GLFW_KEY_E))
				{
					cam.Position.y -= deltaTime * 10;
				}
				else if (glfwGetKey(window.m_window, GLFW_KEY_Q))
				{
					cam.Position.y += deltaTime * 10;
				}
			} // move

			// bind & setup
			{  
				shader->Bind();
				vb->Bind();
				ib->Bind();
				va->Bind();
				texture->Bind();

				shader->SetUniformMat4("model", model);
				shader->SetUniformMat4("projection", cam.GetProjectionMatrix());
				shader->SetUniformMat4("view", cam.GetViewMatrix());
			}
			glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(float), GL_UNSIGNED_INT, 0);


		}
	}
}

