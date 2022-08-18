#pragma once

namespace Jaguar
{
	class RendererAPI
	{
	public:
		static enum class API
		{
			None = 0, OpenGL = 1
		};

		// void SetAPI(API api) { s_API=api; };
		static API Get_API() { return s_API; };
		
	private:
		const static API s_API = API::OpenGL;
	};

	// RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;
	
}