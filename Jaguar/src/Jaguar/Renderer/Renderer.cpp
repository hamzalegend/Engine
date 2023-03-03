#include "Renderer.h"
#include <Jaguar/Log/log.h>

#include "RenderCommand.h"

namespace Jaguar
{
	static Camera* m_SceneCamera;

	Renderer::Renderer(API api)
	{
	}
	
	Renderer::~Renderer()
	{
	}
	void Renderer::Init(API api)
	{
		RenderCommand::InitAPI();
		RenderCommand::SetClearColor(Vector4(1.0f, 0.5f, 1.0f, 1.0f));
	}

	void Renderer::BeginScene(Camera* camera)
	{
		m_SceneCamera = camera;
		RenderCommand::Clear();
	}

	void Renderer::Submit(VertexArray* va, Shader* shader, Mat4& transform)
	{
		shader->Bind();
		shader->SetUniformMat4("model", transform);
		shader->SetUniformMat4("projection", m_SceneCamera->GetProjectionMatrix());
		shader->SetUniformMat4("view", m_SceneCamera->GetViewMatrix());

		va->Bind();
		va->GetIndexBuffer()->Bind();
		RenderCommand::DrawIndexed(va->GetIndexBuffer()->getCount());
	}
	
	void Renderer::Submit(Mesh& mesh, Mat4& transform)
	{
		VertexBuffer* vb = VertexBuffer::Create(&mesh.Vertices[0], mesh.Vertices.size() * sizeof(float));
		vb->Bind();
		IndexBuffer* ib = IndexBuffer::Create(mesh.indices.data(), sizeof(mesh.indices) / sizeof(float));
		ib->Bind();
		VertexArray* va = VertexArray::Create();
		va->SetIndexBuffer(ib);
		va->Bind();
		va->AddLayout(3);
		va->AddLayout(4);
		va->AddLayout(2);
		va->Push();

		Shader* shader = Shader::Create("src/shaders/basic.vshader", "src/shaders/basic.fshader");
		shader->Bind();

		shader->SetUniformMat4("model", transform);
		shader->SetUniformMat4("projection", m_SceneCamera->GetProjectionMatrix());
		shader->SetUniformMat4("view", m_SceneCamera->GetViewMatrix());

		va->GetIndexBuffer()->Bind();
		RenderCommand::DrawIndexed(va->GetIndexBuffer()->getCount());

		delete vb, ib, va, shader;
	}

	void Renderer::Flush()
	{
	}

	void Renderer::EndScene()
	{
	}
}
