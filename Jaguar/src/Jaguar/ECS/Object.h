#pragma once

#include "../Log/log.h"
#include "API/Shader.h"
#include "API/Buffer.h"
#include "../Math.h"

namespace Jaguar {

	class Object
	{
	public:
		Mat4 Transform;
		Vector3 color;
		// Texture texture = Texture();

		Shader* shader;
		VertexBuffer* vb;
		IndexBuffer* ib;
		VertexArray* va;

		Object();
		~Object();

		void Draw();

	private:

	};
}

/*

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
*/