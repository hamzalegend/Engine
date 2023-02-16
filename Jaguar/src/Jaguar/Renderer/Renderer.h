#pragma once
#include <Jaguar/Math.h>
#include <API/Shader.h>

#include "API/Buffer.h"
#include <Jaguar/Camera/Camera.h>

namespace Jaguar
{
	// class RendererAPI
	// {
	// public:
	// 
	// 	// void SetAPI(API api) { s_API=api; };
	// 	
	// private:
	// };
	// 
	// // RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;



	class Renderer
	{
	public:
		static enum class API
		{
			None = 0, OpenGL = 1
		};

		Renderer(API api);
		~Renderer();
	public:
		static API Get_API() { return API::OpenGL; };
	
		static void Init(API api);
		static void BeginScene(Camera* camera);
		static void Submit(VertexArray* va, Shader* shaer, Mat4 transform);
		static void EndScene();
		static void Flush();
		static API s_API;
	private:
	};


}
	
	
