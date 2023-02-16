#pragma once
#include "Jaguar/Math.h"


namespace Jaguar
{
	class RendererAPI
	{
	public:
		virtual void Init() = 0;
		virtual void Clear() = 0;
		virtual void SetClearColor(Vector4 color) = 0;
		virtual void DrawIndexed(int count) = 0;
	private:
	
	};
}