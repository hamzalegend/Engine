#pragma once

#include "RendererAPI.h"

namespace Jaguar
{
	class RenderCommand
	{
	public:
		// RenderCommand();
		static inline void InitAPI() { s_RendererAPI->Init(); };
		static  void Clear();
		static  void SetClearColor(Vector4 color);
		static void DrawIndexed(int count);
	
		static RendererAPI* s_RendererAPI;
	private:
		
	
	};
}