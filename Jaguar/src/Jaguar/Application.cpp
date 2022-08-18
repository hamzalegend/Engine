#include "GL/glew.h"
#include "Application.h"
#include "Window/Window.h"
#include "Log/log.h"
#include "../API/OpenGL/ShaderGL.h"
#include "../API/OpenGL/BufferGL.h"
#include "Renderer/Renderer.h"
#include <iostream>


namespace Jaguar {


	float vertices[] = {
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
		
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		float verticesTriangle[] = {
		// pos____  |color_________________
		-0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
		 0.5f,-0.5f, 0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f,-0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f,
		};
		unsigned int indices[] = {
			0,1,2,
			0,3,1,
		};

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glViewport(0, 0, window.width, window.height);

		if (RendererAPI::Get_API() == RendererAPI::API::OpenGL) 
			JR_CORE_INFO("Using OpenGL as the Defult API");


		Shader* shader = Shader::Create("src/shaders/basic.vshader", "src/shaders/basic.fshader");
		shader->Bind();	

		VertexBuffer* vb = VertexBuffer::Create(verticesTriangle, sizeof(vertices));
		vb->Bind();

		IndexBuffer* ib = IndexBuffer::Create(indices, 6);
		ib->Bind();

		VertexArray* va = VertexArray::Create();
		va->Bind();
		va->AddLayout(2); // positions
		va->AddLayout(4); // colors
		va->Push(); // pushing to GPU;



		while (!glfwWindowShouldClose(window.m_window))
		{			
			
			shader->Bind();
			vb->Bind();
			va->Bind();
			ib->Bind();

			window.Refresh();

			// glDrawArrays(GL_TRIANGLES, 0, 3);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			shader->UnBind();
			vb->UnBind();
			va->UnBind();
			ib->UnBind();

		}
	}
}
