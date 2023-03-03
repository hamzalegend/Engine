#pragma once

#include "Mesh.h""

#include "API/Buffer.h"
#include "API/Shader.h"

#include "Jaguar/Camera/Camera.h"

#include <Jaguar/Math.h>

namespace Jaguar
{
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
		static void Submit(Mesh& mesh,Mat4& transform);
		static void Submit(VertexArray* va, Shader* shaer, Mat4& transform);
		static void EndScene();
		static void Flush();

		static API s_API;
	private:
	};
}
	
	
