#include "Object.h"
#include <GL/glew.h>
#include "Jaguar/Log/log.h"

#include "GLFW/glfw3.h"
// #include <Jaguar/Camera/Camera.h>

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

namespace Jaguar
{
	Object::Object()
	{
		model = Mat4(1);
		
		vb = VertexBuffer::Create(Vertices, sizeof(Vertices));
		vb->Bind();

		ib = IndexBuffer::Create(indices, sizeof(indices) / sizeof(float));
		ib->Bind();

		va = VertexArray::Create();

		va->Bind();
		va->AddLayout(3);
		va->AddLayout(4);
		va->AddLayout(2);
		va->Push();
		
		shader = Shader::Create("src/shaders/basic.vshader", "src/shaders/basic.fshader");
		shader->Bind();
	}
	

	void Object::Draw()
	{
		shader->Bind();
		vb->Bind();
		ib->Bind();
		va->Bind();
		if (m_hasTexture)
			texture->Bind();

		// shader->SetUniformMat4("model", model);

		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(float), GL_UNSIGNED_INT, 0);


		shader->UnBind();
		vb->UnBind();
		ib->UnBind();
		// va->UnBind();
		if (m_hasTexture)
			texture->UnBind();
	}

	void Object::AddTexture(std::string path, int index, int number, bool isTransparent)
	{
		std::string name = "Texture" + std::to_string(number);
		texture = Texture::Create(path, index, isTransparent);

		// delete shader;
		shader = Shader::Create("src/shaders/Texture.vshader", "src/shaders/Texture.fshader");

		texture->Bind();
		shader->Bind();

		shader->SetUniform1i(name.c_str(), index);

		shader->UnBind();
		texture->UnBind();
		m_hasTexture = true;
	}

	Object::~Object()
	{
	}
}



// VertexBuffer* vb;
// IndexBuffer* ib;
// VertexArray* va;
// Shader* shader;
// Texture* texture;
// 
// vb = VertexBuffer::Create(Vertices, sizeof(Vertices));
// vb->Bind();
// ib = IndexBuffer::Create(indices1, 6);
// ib->Bind();
// va = VertexArray::Create();
// va->Bind();
// va->AddLayout(3);
// va->AddLayout(4);
// va->AddLayout(2);
// va->Push();
// 
// shader = Shader::Create("src/shaders/texture.vshader", "src/shaders/texture.fshader");
// shader->Bind();
// 
// texture = Texture::Create("src/Images/logo.jpeg", 0, false);
// texture->Bind();
// 
// shader->SetUniform1i("Texture0", 0);




/// muheeeem jidan!!
// add camera orth or perspectiveve zai ma bidak the try and make a game i guess?!