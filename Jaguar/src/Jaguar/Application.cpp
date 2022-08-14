#include "GL/glew.h"
#include "Application.h"
#include "Window/Window.h"
#include "Log/log.h"
#include "../API/OpenGL/ShaderGL.h"
#include "../API/OpenGL/BufferGL.h"


namespace Jaguar {


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
		float vertices[] = {
		-0.5f, 0.5f,
		 0.5f,-0.5f,
		-0.5f,-0.5f,
		 0.5f, 0.5f,
		};
		unsigned int indices[] = {
			0,1,2,
			0,3,1,
		};

		Shader shader("src/shaders/basic.vshader", "src/shaders/basic.fshader");
		shader.Bind();	


		VertexBuffer* vb = VertexBuffer::Create(vertices, sizeof(vertices));
		vb->Bind();

		unsigned int vao;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
		glEnableVertexAttribArray(0);

		IndexBuffer* ib = IndexBuffer::Create(indices, 6);
		ib->Bind();

		while (true)
		{			
			
			vb->Bind();
			glBindVertexArray(vao);
			
			ib->Bind();

			window.Refresh();
			// glDrawArrays(GL_TRIANGLES, 0, 3);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			vb->UnBind();
			glBindVertexArray(0);
			ib->UnBind();

		}
	}
}
