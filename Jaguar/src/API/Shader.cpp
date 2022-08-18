#include "Shader.h"
#include "../Jaguar/Renderer/Renderer.h"
#include "OpenGL/ShaderGL.h"

namespace Jaguar
{


	Shader* Shader::Create(std::string VertexPath, std::string FragmentPath)
	{
		switch (RendererAPI::Get_API())
		{
		case(RendererAPI::API::OpenGL):
			return new ShaderGL(VertexPath.c_str(), FragmentPath.c_str());
		default:
			break;
		}
		return nullptr;
	}
}