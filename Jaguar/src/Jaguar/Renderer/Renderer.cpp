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
	}

	void Renderer::Submit(VertexArray* va, Shader* shader, Mat4 transform)
	{
		RenderCommand::Clear();

		shader->Bind();
		shader->SetUniformMat4("model", transform);
		shader->SetUniformMat4("projection", m_SceneCamera->GetProjectionMatrix());
		shader->SetUniformMat4("view", m_SceneCamera->GetViewMatrix());

		va->Bind();
		va->GetIndexBuffer()->Bind();
		RenderCommand::DrawIndexed(va->GetIndexBuffer()->getCount());
	}

	void Renderer::Flush()
	{
	}

	void Renderer::EndScene()
	{
	}
}
