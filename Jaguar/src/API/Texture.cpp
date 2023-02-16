#include "Texture.h"
#include "API/OpenGL/TextureGL.h"
#include "Jaguar/Renderer/Renderer.h"
namespace Jaguar
{

	Texture* Texture::Create(std::string path, int Index, bool isTransparent)
	{
		switch (Renderer::Get_API())
		{
		case(Renderer::API::OpenGL):
			return new TextureGL(path, Index, isTransparent);
		default:
			break;
		}
		return nullptr;
	}

}