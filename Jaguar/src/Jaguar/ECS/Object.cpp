#include "Object.h"
#include <GL/glew.h>


float TriangleVertices[] = {
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

namespace Jaguar
{
	Object::Object()
	{
		Transform = Mat4(1);


		Transform = glm::scale(Transform, Vector3(0.5f, 0.5f, 0.0f));
		Transform = glm::rotate(Transform, glm::radians(45.0f), glm::vec3(0.0, 0.0, 1.0));

		color = Vector3(1);
		// texture = Texture();


		// ========================================================================================
		shader = Shader::Create("src/shaders/basic.vshader", "src/shaders/basic.fshader");
		vb = VertexBuffer::Create(TriangleVertices, sizeof(TriangleVertices));
		ib = IndexBuffer::Create(indices, 6);
		va = VertexArray::Create();

		va->Bind();

		va->AddLayout(2); // positions
		va->AddLayout(4); // colors
		va->Push(); // pushing to GPU;

		va->UnBind();
		
	}

	void Object::Draw()
	{
		shader->Bind();
		vb->Bind();
		ib->Bind();
		va->Bind();
		shader->SetUniform(Transform);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		shader->UnBind();
		vb->UnBind();
		// va->UnBind();
		ib->UnBind();

	}


	Object::~Object()
	{
	}
}