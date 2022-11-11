#include "Object.h"
#include <GL/glew.h>
#include "Jaguar/Log/log.h"

float TriangleVertices[] = {
	// positions          // colors           // texture coords
	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
	// // pos____  |color_________________
	// -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
	//  0.5f,-0.5f, 0.0f, 1.0f, 0.0f, 1.0f,
	// -0.5f,-0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
	//  0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f,
};

unsigned int indices[] = {
	0, 1, 3,
	1, 2, 3,
};

namespace Jaguar
{
	Object::Object()
	{
		Transform = Mat4(1);
		color = Vector3(1);

		shader = Shader::Create("src/shaders/basic.vshader", "src/shaders/basic.fshader");
		vb = VertexBuffer::Create(TriangleVertices, sizeof(TriangleVertices));
		ib = IndexBuffer::Create(indices, 6);
		va = VertexArray::Create();


		va->Bind();
		va->AddLayout(3); // positions
		va->AddLayout(3); // colors
		va->AddLayout(2); // TexCoords
		va->Push(); // pushing to GPU;
		va->UnBind();		

	}

	void Object::Draw()
	{
		shader->Bind();
		vb->Bind();
		ib->Bind();
		va->Bind();
		if (hasTexture)
			texture->Bind();

		shader->SetUniformMat4("Transform", Transform);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


		shader->UnBind();
		vb->UnBind();
		ib->UnBind();
		// va->UnBind();
		if (hasTexture)
			texture->UnBind();
	}

	void Object::AddTexture(std::string path, int index, int number)
	{
		std::string name = "Texture" + std::to_string(number);
		texture = Texture::Create(path, index, false);

		delete shader;
		shader = Shader::Create("src/shaders/basic.vshader", "src/shaders/Texture.fshader");

		texture->Bind();
		shader->Bind();

		shader->SetUniform1i("Texture0", index);

		shader->UnBind();
		texture->UnBind();
		hasTexture = true;
	}

	Object::~Object()
	{
	}
}

