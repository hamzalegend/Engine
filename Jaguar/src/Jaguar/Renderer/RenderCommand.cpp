#include "RenderCommand.h"
#include "RendererAPIOpenGL.h"

#include "Jaguar/Log/log.h" // remove


namespace Jaguar
{

	RendererAPI* RenderCommand::s_RendererAPI = new RendererAPIOpenGL();

	void RenderCommand::Clear()
	{
		s_RendererAPI->Clear();
	}
	
	void RenderCommand::SetClearColor(Vector4 color)
	{
		s_RendererAPI->SetClearColor(color);
	}
	
	void RenderCommand::DrawIndexed(int count)
	{
		s_RendererAPI->DrawIndexed(count);
	}

}